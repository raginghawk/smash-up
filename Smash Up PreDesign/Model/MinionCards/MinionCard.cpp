#include "MinionCard.h"
#include <ActionCard.h>
#include <Base.h>
#include <Board.h>
#include <Player.h>

MinionCard::MinionCard(Player *owner)
{
	this->initOwner(owner);
	_powerModification = 0;
	_destoryProtectionCounter = 0;
	_cardType = BASE_CARD;
}

bool MinionCard::isMinion()
{
	return true;
}

std::vector<ActionCard *> MinionCard::actionsOnMinion()
{
	return _actions;
}

int MinionCard::printedPower()
{
	return _printedPower;
}

int MinionCard::powerModification()
{
	return _powerModification;
}

int MinionCard::currentPower()
{
	return currentPower(this);
}

int MinionCard::currentPower(MinionCard *card)
{
	int powerModification = card->powerModification();
	powerModification += card->currentOwner()->minionPowerModification();
	return card->printedPower() + powerModification;
}

bool MinionCard::isAffectable()
{
	return true;
}

bool MinionCard::hasTalent()
{
	return _talent;
}

void MinionCard::removeAllActions()
{
	std::vector<ActionCard *>::iterator itActions;
	for (itActions = _actions.begin(); itActions != _actions.end(); itActions++)
	{
		(*itActions)->destroy();
	}
}

void MinionCard::modifyCurrentPower(int modification)
{
	_powerModification += modification;
}

void MinionCard::modifyDestoryCount(int modification)
{
	_destoryProtectionCounter += modification;
	assert(_destoryProtectionCounter >= 0); /*should never have less than zero because that means there are negitive cards/affects protecting it*/
	assert(modification == 1 || modification == -1); /*you should only increment and decrement by one*/
}

void MinionCard::modifyAffectAbleCount(int modification)
{
	_affectableCounter += modification;
	assert(_affectableCounter >= 0); /* should never have less than zero because that means there ar enegitive cards protecting it*/
	assert(modification == 1 || modification == -1);
}

void MinionCard::destroy()
{
	destroy(this);
}

void MinionCard::destroy(MinionCard *card)
{
	if (!_destoryProtectionCounter)
		_base->destroyMinion(card);
}

bool MinionCard::fPlay(Player *player)
{
	if (vBoard->bases().size() == 0)
		return false;

	std::vector<MinionPlayableStruct *> minionsRemaining = player->minionsRemaining();
	std::vector<MinionPlayableStruct *>::iterator itMinionStruct;

	bool found = false;
	for (itMinionStruct = minionsRemaining.begin(); itMinionStruct != minionsRemaining.end(); itMinionStruct++)
	{
		if (printedPower() <= (*itMinionStruct)->maxPower())
		{
			found = true;
			break;
		}
	}
	if (!found)
		return false;

	return true;
}

void MinionCard::play(Base *base, MinionCard *card)
{
	base->playMinion(card);
}

void MinionCard::play(Base *base)
{
	play(base, this);
}

void MinionCard::play()
{
	assert(true); /*Minion Card's are never instant*/
}

void MinionCard::play(MinionCard *minion, ActionCard *action)
{
	assert(true); /* minion card's can't play on other minion cards*/
}

bool MinionCard::fUpdate(UpdateVisibilityFlags *flags)
{
	std::vector<ActionCard *>::iterator itActions;
	
	for (itActions = _actions.begin(); itActions != _actions.end(); itActions++)
	{
		if ((*itActions)->fUpdate(flags))
		{
			return true;
		}
	}
	return false;
}

void MinionCard::update(Base *base)
{

}

void MinionCard::update(UpdateVisibilityFlags *flags)
{
	std::vector<ActionCard *>::iterator itActions;

	for (itActions = _actions.begin(); itActions != _actions.end(); itActions++)
	{
		if ((*itActions)->fUpdate(flags))
		{
			(*itActions)->update(this);
		}
	}
}

void MinionCard::move(Base *newBase)
{

	std::vector<MinionCard *>::iterator itMinions = std::find(_base->minionsOnBase().begin(), _base->minionsOnBase().end(), this);
	if (itMinions == _base->minionsOnBase().end())
	{
		assert(true); /*Couldn't find minion*/
		return;
	}

	_base->minionsOnBase().erase(itMinions);
	newBase->moveMinion(this);
	_base = newBase;
}

void MinionCard::discard()
{
	//TODO not sure
}

void MinionCard::useTalent(Player *owner, MinionCard *card)
{
	// any Minion with a talent should override this method
	assert(false);
}
