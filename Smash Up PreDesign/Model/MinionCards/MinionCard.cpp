#include "MinionCard.h"
#include <ActionCard.h>
#include <Base.h>
#include <Board.h>
#include <Player.h>

MinionCard::MinionCard(Player *owner)
{
	this->initOwner(owner);
	_powerModification = 0;
	_destroyProtectionCounter = 0;
	_cardType = BASE_CARD;
}

#pragma region static
std::vector<MinionCard *> MinionCard::minionsWithPowerLessThan(int limPower, std::vector<MinionCard *> options)
{
	std::vector<MinionCard *>minions;
	std::vector<MinionCard *>::iterator itCards;

	for (itCards = options.begin(); itCards != options.end(); itCards++)
	{
		if ((*itCards)->printedPower() < limPower)
		{
			minions.push_back(*itCards);
		}
	}

	return minions;
}

#pragma endregion
bool MinionCard::isMinion()
{
	return true;
}

bool MinionCard::hasTalent()
{
	return _talent;
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
	powerModification += card->base()->powerModification(card->currentOwner());

	if (card->printedPower() + powerModification < 0)
		return 0;

	return card->printedPower() + powerModification;
}

bool MinionCard::isAffectable()
{
	return _affectableCounter == 0;
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

void MinionCard::modifyAffectAbleCount(int modification)
{
	_affectableCounter += modification;
	assert(_affectableCounter >= 0); /* should never have less than zero because that means there ar enegitive cards protecting it*/
	assert(modification == 1 || modification == -1);
}

bool MinionCard::destroy()
{
	return destroy(this);
}

bool MinionCard::destroy(MinionCard *card)
{
	if (fDestroyable(card))
	{
		_base->destroyMinion(card);
		return true;
	}
	return false;
}

void MinionCard::modifyDestroyCount(int modification)
{
	_destroyProtectionCounter += modification;
	assert(_destroyProtectionCounter >= 0); /*should never have less than zero because that means there are negitive cards/affects protecting it*/
	assert(modification == 1 || modification == -1); /*you should only increment and decrement by one*/
}

bool MinionCard::fDestroyable()
{
	return fDestroyable(this);
}

bool MinionCard::fDestroyable(MinionCard *card)
{
	return _destroyProtectionCounter == 0;
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

bool MinionCard::fPlay(Player *player, Base *base)
{
	//TODO Figure this and the other fPlay out :/
	return true;
}

void MinionCard::play(Base *base)
{
	play(base, this);
}

void MinionCard::play(Base *base, MinionCard *card)
{
	base->playMinion(card);
}

bool MinionCard::fMovable(Base *newBase)
{
	//TODO check current base if it is movable
	return true;
}


void MinionCard::move(Base *newBase)
{
	if (fMovable(newBase))
	{
		_base->removeCard(this);
		newBase->moveCard(this);
	}
}

void MinionCard::discard()
{
	discard(this);
}

void MinionCard::discard(MinionCard *card)
{
	card->removeAllActions();
	_base->removeCard(card);
	_base = NULL;

	card->owner()->addCardToDiscardPile(card);
}

void MinionCard::useTalent(Player *owner, MinionCard *card)
{
	assert(false);
}

void MinionCard::returnToOwnersHand()
{
	this->removeAllActions();
	_base->removeCard(this);
	_owner->addCardToHand(this);
}
