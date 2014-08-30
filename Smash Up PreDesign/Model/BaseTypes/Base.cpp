#include "Base.h"
#include <Player.h>
#include <MinionCard.h>

Base::Base()
{
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
	_powerModification.at(owner->playerNumber()) += modification;
}


void Base::moveMinion(MinionCard *minion)
{
	_minionsOnBase.push_back(minion);
}

void Base::playMinion(MinionCard *minion)
{
	_minionsOnBase.push_back(minion);
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