#include "Base.h"
#include <Player.h>
#include <MinionCard.h>

Base::Base(std::vector<Player *>players)
{
	breakingPoint = 12; /*Hard Code for now will be set by subclasses*/
	_powerModification.clear(); /*just to be safe when you pull a base from the grave*/
	
	std::vector<Player *>::iterator itPlayers;
	for (itPlayers = players.begin(); itPlayers != players.end(); itPlayers++)
	{
		_powerModification.insert(std::make_pair(*itPlayers, 0));
	}
}


std::vector<MinionCard *> Base::minionsOnBase()
{
	return _minionsOnBase;
}

std::vector<ActionCard *> Base::actionsOnBase()
{
	return _actionsOnBase;
}

void Base::modifyPower(int modification, Player *owner)
{
	_powerModification[owner] += modification;
}

void Base::moveMinion(MinionCard *minion)
{
	_minionsOnBase.push_back(minion);
}

void Base::playMinion(MinionCard *minion)
{
	_minionsOnBase.push_back(minion);
	minion->setBase(this);
}

void Base::destroyMinion(MinionCard *minion)
{
	auto itMinions = std::find(_minionsOnBase.begin(), _minionsOnBase.end(), minion);
	if (itMinions == _minionsOnBase.end())
	{
		return;
		assert(false); // Couldn't find minion
	}
		
	this->removeMinion(*itMinions);
}

void Base::removeMinion(MinionCard *minion)
{
	auto itMinions = std::find(_minionsOnBase.begin(), _minionsOnBase.end(), minion);
	if (itMinions == _minionsOnBase.end())
	{
		return;
		assert(false); // Couldn't find minion
	}

	_minionsOnBase.erase(itMinions);
	minion->removeAllActions();
}


bool Base::isBreaking()
{
	return currentPowerOnBase() >= breakingPoint;
}

int Base::currentPowerOnBase()
{
	int runningPower = 0;
	int minionPower;
	std::vector<MinionCard *>::iterator itMinions;
	
	for (itMinions = _minionsOnBase.begin(); itMinions != _minionsOnBase.end(); itMinions++)
	{
		minionPower = (*itMinions)->currentPower(*itMinions) + _powerModification[(*itMinions)->currentOwner()];
		if (minionPower > 0)
			runningPower += minionPower;
	}

	return runningPower;
}