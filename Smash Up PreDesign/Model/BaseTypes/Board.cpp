#include "Board.h"
#include "Base.h"
#include <MinionCard.h>
#include <Player.h>

Board::Board(std::vector<Player *> players)
{
	_players = players;
}

std::vector<Base *> Board::bases()
{
	return _bases;
}

Player * Board::currentPlayer()
{
	return _currentPlayer;
}

std::vector<MinionCard *> Board::minionsOnBases(Base *base)
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
		minionsInPlay.reserve(minionsInPlay.size() + (*itBases)->minionsOnBase().size());
		minionsInPlay.insert(minionsInPlay.end(), (*itBases)->minionsOnBase().begin(), (*itBases)->minionsOnBase().end());
	}

	return minionsInPlay;
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
	for (itPlayers = _players.begin(); itPlayers != _players.end(); itPlayers++)
	{
		(*itPlayers)->drawCard(5);
	}


	//TODO pick random player
	int currentPlayer = 0;
	while (true)
	{
		_players.at(currentPlayer)->takeTurn();
		//TODO eval bases
	}
}