#include "Board.h"
#include "Base.h"
#include <MinionCard.h>
#include <Player.h>
#include <algorithm>	/* random_shuffle*/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <Event.h>

Board::Board(std::vector<Player *> players)
{
	_players = players;
	initBases();
}

Board::~Board()
{
	delete(_baseWillScore);
}

void Board::initBases()
{
	_baseWillScore = new Event(new EventData(BASE_WILL_SCORE));

	/* Temp Loop to add some bases. In the future will probably have it similar to addGhosts or something in DeckConstructor.cpp*/
	for (int i = 0; i < 10; i++)
	{
		_baseDeck.push_back(new Base(_players));
	}

	std::srand(unsigned(time(0)));
	std::random_shuffle(_baseDeck.begin(), _baseDeck.end());

	for (unsigned int i = 0; i < (1 + _players.size()); i++)
	{
		drawBase();
	}
}

std::vector<Player *> Board::players()
{
	return _players;
}


Event *Board::baseWillScore()
{
	return _baseWillScore;
}


void Board::drawBase()
{
	//TODO should there be a check about bases remaining :/
	_bases.push_back(_baseDeck.back());
	_baseDeck.pop_back();
}

std::vector<Base *> Board::bases()
{
	return _bases;
}

std::vector<Base *> Board::otherBases(Base *base)
{
	std::vector<Base *> toReturn = _bases;
	std::vector<Base *>::iterator itBases = std::find(toReturn.begin(), toReturn.end(), base);
	if (itBases == _bases.end())
		assert(false); // Couldn't find the base

	toReturn.erase(itBases);
	return toReturn;
}

std::vector<Base *> Board::basesWithMinionFromPlayer(Player *player)
{
	std::vector<Base *> toReturn = _bases;
	std::vector<Base *>::iterator itBases;
	
	for (itBases = _bases.begin(); itBases != _bases.end(); itBases++)
	{
		if ((*itBases)->minionsFromPlayer(player).size() == 0)
			toReturn.erase(itBases);
	}
	return toReturn;
}

Player * Board::currentPlayer()
{
	return _currentPlayer;
}

std::vector<MinionCard *> Board::minionsOnBase(Base *base)
{
	return base->minionsOnBase();
}

std::vector<MinionCard *> Board::minionsInPlay()
{
	std::vector<MinionCard *> minionsInPlay;
	if (_bases.begin() == _bases.end())
		return minionsInPlay;

	std::vector<Base *>::iterator itBases = _bases.begin();
	minionsInPlay = (*itBases)->minionsOnBase();

	for (itBases = _bases.begin()+1; itBases != _bases.end(); itBases++)
	{
		if ((*itBases)->minionsOnBase().size() != 0)
		{
			minionsInPlay.reserve(minionsInPlay.size() + (*itBases)->minionsOnBase().size());
			minionsInPlay.insert(minionsInPlay.end(), (*itBases)->minionsOnBase().begin(), (*itBases)->minionsOnBase().end());
		}
	}

	return minionsInPlay;
}

std::vector<MinionCard *> Board::minionsWithPowerLessThan(int limPower)
{
	std::vector<MinionCard *> minionsInPlay;
	if (_bases.begin() == _bases.end())
		return minionsInPlay;

	std::vector<Base *>::iterator itBases = _bases.begin();
	minionsInPlay = (*itBases)->minionsWithPowerLessThan(limPower);

	for (itBases = _bases.begin() + 1; itBases != _bases.end(); itBases++)
	{
		std::vector<MinionCard *> basesMinions = (*itBases)->minionsWithPowerLessThan(limPower);
		if (basesMinions.size() == 0)
		{
			minionsInPlay.reserve(minionsInPlay.size() + basesMinions.size());
			minionsInPlay.insert(minionsInPlay.end(), basesMinions.begin(), basesMinions.end());
		}
	}

	return minionsInPlay;
}

std::vector<ActionCard *> Board::actionsOnMinions()
{
	std::vector<ActionCard *> actionsOnMinions;
	std::vector<MinionCard *> minionsInPlay = this->minionsInPlay();
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minionsInPlay.begin(); itMinions != minionsInPlay.end(); itMinions++)
	{
		std::vector<ActionCard *> actionsOnMinion = (*itMinions)->actionsOnMinion();
		if (actionsOnMinion.size() != 0)
		{
			actionsOnMinions.reserve(actionsOnMinions.size() + actionsOnMinion.size());
			actionsOnMinions.insert(actionsOnMinions.end(), actionsOnMinion.begin(), actionsOnMinion.end());
		}
	}

	return actionsOnMinions;
}

std::vector<MinionCard *> Board::otherPlayersMinionsInPlay(Player *player)
{
	std::vector<MinionCard *> minionsInPlay = this->minionsInPlay();
	std::vector<MinionCard *> otherPlayersMinions;
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minionsInPlay.begin(); itMinions != minionsInPlay.end(); itMinions)
	{
		if ((*itMinions)->currentOwner() != player)
		{
			otherPlayersMinions.push_back(*itMinions);
		}
	}

	return otherPlayersMinions;
}

std::vector<MinionCard *> Board::playersMinionsInPlay(Player *player)
{
	std::vector<MinionCard *> minionsInPlay = this->minionsInPlay();
	std::vector<MinionCard *> playersMinions;
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minionsInPlay.begin(); itMinions != minionsInPlay.end(); itMinions)
	{
		if ((*itMinions)->currentOwner() == player)
		{
			playersMinions.push_back(*itMinions);
		}
	}

	return playersMinions;
}



void Board::startGame()
{
	std::vector<Player *>::iterator itPlayers;
	Player *winner;
	for (itPlayers = _players.begin(); itPlayers != _players.end(); itPlayers++)
	{
		(*itPlayers)->drawCard(5);
	}

	//TODO pick random player
	int currentPlayer = 0;
	while (true)
	{
		_currentPlayer = _players.at(currentPlayer);
		_currentPlayer->takeTurn();
		
		evaulateBases();

		_currentPlayer->endTurn();

		if ((winner = pWinnerIfGameOver()))
			break;

		currentPlayer++;
		if (currentPlayer == _players.size())
		{
			currentPlayer = 0;
		}
	}
	// TODO display winner
	printf("Winner is %d", &winner);
}

void Board::evaulateBases()
{
	std::vector<Base *>::iterator itBases;

	for (itBases = _bases.begin(); itBases != _bases.end(); itBases++)
	{
		if ((*itBases)->isBreaking())
		{
			//TODO select which base breaks first (user choice :/) probably need to add it to a vector of bases that are breaking and have the user select. After each base breaks you have to reevaulate
			// whether every base is breaking or not :/ that makes this temp code ... ugh
			_baseWillScore->eventData()->setBase(*itBases);
			_baseWillScore->fireEvent();
			(*itBases)->scoreBase();
			(*itBases)->discardBase();

			std::vector<Base *>::iterator basePosition = std::find(_bases.begin(), _bases.end(), *itBases);
			if (basePosition != _bases.end())
				_bases.erase(basePosition);
			else
				assert(true); // base shouldn't already be off the board :/
			
			drawBase();
		}
	}
}


Player * Board::pWinnerIfGameOver()
{
	std::vector<Player *>::iterator itPlayers;
	int maxScore = 0;
	Player *winner = NULL;

	for (itPlayers = _players.begin(); itPlayers != _players.end(); itPlayers++)
	{
		if ((*itPlayers)->currentVictoryPoints() > 14)
		{
			if ((*itPlayers)->currentVictoryPoints() > maxScore)
			{
				maxScore = (*itPlayers)->currentVictoryPoints();
				winner = *itPlayers;
			}
			else if ((*itPlayers)->currentVictoryPoints() == maxScore)
			{
				winner = NULL;
			}
		}
	}

	return winner;
}