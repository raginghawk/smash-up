#include "Base.h"
#include <Player.h>
#include <Event.h>
#include <MinionCard.h>
#include <ActionCard.h>
#include <algorithm>

Base::Base(std::vector<Player *>players)
{
	breakingPoint = 12; /*Hard Code for now will be set by subclasses*/
	_powerModification.clear(); /*just to be safe when you pull a base from the grave*/
	
	std::vector<Player *>::iterator itPlayers;
	for (itPlayers = players.begin(); itPlayers != players.end(); itPlayers++)
	{
		_powerModification.insert(std::make_pair(*itPlayers, 0));
	}

	_baseDidScore = new Event(new EventData(this, BASE_DID_SCORE));
}

Base::~Base()
{
	delete(_baseDidScore);
}

std::vector<MinionCard *> & Base::minionsOnBase()
{
	return _minionsOnBase;
}

std::vector<ActionCard *> & Base::actionsOnBase()
{
	return _actionsOnBase;
}

std::vector<MinionCard *> Base::minionsFromPlayer(Player * player)
{
	std::vector<MinionCard *> toReturn = _minionsOnBase;
	
	toReturn.erase(std::remove_if(toReturn.begin(),
		toReturn.end(), 
		[player](MinionCard *card) { return card->currentOwner() == player; }),
		toReturn.end()); //TODO check cause its complicated

	return toReturn;
}

std::vector<MinionCard *> Base::otherPlayersMinions(Player *player)
{
	std::vector<MinionCard *> toReturn = _minionsOnBase;

	toReturn.erase(std::remove_if(toReturn.begin(),
		toReturn.end(),
		[player](MinionCard *card) { return card->currentOwner() != player; }),
		toReturn.end()); //TODO check cause its complicated

	return toReturn;
}


std::vector<MinionCard *> Base::minionsWithPowerLessThan(int limPower, std::vector<MinionCard *> options)
{
	if (options.size() == 0)
		return options;

	options.erase(std::remove_if(options.begin(),
		options.end(),
		[limPower](MinionCard *card) {return card->currentPower() < limPower; }),
		options.end()); // TODO Check with minionsFromPlayer

	return options;
}

std::vector<MinionCard *> Base::minionsFromPlayerWithPowerLessThan(Player *player, int limPower)
{
	std::vector<MinionCard *> options = minionsFromPlayer(player);
	return minionsWithPowerLessThan(limPower, options);
}

std::vector<MinionCard *> Base::minionsWithPowerLessThan(int limPower)
{
	std::vector<MinionCard *> options = _minionsOnBase;
	return minionsWithPowerLessThan(limPower, options);
}

std::vector<MinionCard *> Base::minionsOfFaction(Faction faction)
{
	std::vector<MinionCard *> toReturn = _minionsOnBase;

	toReturn.erase(std::remove_if(toReturn.begin(),
		toReturn.end(),
		[faction](MinionCard *card) { return card->faction() == faction; }),
		toReturn.end()); //TODO check cause its complicated

	return toReturn;
}


Event * Base::baseDidScore()
{
	return _baseDidScore;
}


void Base::modifyPower(int modification, Player *player)
{
	_powerModification[player] += modification;
}

int Base::powerModification(Player *player)
{
	return _powerModification[player];
}

void Base::moveCard(MinionCard *minion)
{
	_minionsOnBase.push_back(minion);
	minion->setBase(this);
}

void Base::moveCard(ActionCard *action)
{
	_actionsOnBase.push_back(action);
	action->setBase(this);
}

void Base::removeCard(MinionCard *minion)
{
	std::vector<MinionCard *>::iterator itMinions = std::find(_minionsOnBase.begin(), _minionsOnBase.end(), minion);
	if (itMinions == _minionsOnBase.end())
	{
		return;
		assert(false); // Couldn't find minion
	}

	_minionsOnBase.erase(itMinions);
}

void Base::removeCard(ActionCard *action)
{
	std::vector<ActionCard *>::iterator itActions = std::find(_actionsOnBase.begin(), _actionsOnBase.end(), action);
	if (itActions == _actionsOnBase.end())
	{
		return;
		assert(false); // Couldn't find minion
	}

	_actionsOnBase.erase(itActions);
}


void Base::playMinion(MinionCard *minion)
{
	_minionsOnBase.push_back(minion);
	minion->setBase(this);
}

void Base::destroyMinion(MinionCard *minion)
{
	minion->discard();
}

bool Base::isBreaking()
{
	return currentPowerOnBase() >= breakingPoint;
}

void Base::discardBase()
{
	//TODO call discard on all minions, minions will call discard on their actions. Then call discard on all actions played on the base
}

void Base::scoreBase()
{
	_baseDidScore->fireEvent();
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