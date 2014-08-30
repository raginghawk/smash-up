#include "Board.h"
#include "Base.h"
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