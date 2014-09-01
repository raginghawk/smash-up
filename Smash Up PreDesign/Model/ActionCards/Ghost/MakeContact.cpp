//TODO Steal minion :/
#pragma once
#include "MakeContact.h"
#include <MinionCard.h>
#include <Player.h>

MakeContact::MakeContact(Player *owner) : ActionCard(owner)
{
	this->_name = "Make Contact";
	_cardType = MINION_CARD;
}

bool MakeContact::fUpdate(UpdateVisibilityFlags *flags)
{
	return flags->fOwner;
}

void MakeContact::update(MinionCard *minionCard)
{
	minionCard->setCurrentOwner(_currentOwner);
}

void MakeContact::play(MinionCard *minionCard, ActionCard *action)
{
	_currentOwner = action->currentOwner();
	_selection = minionCard;
	_selection->setCurrentOwner(_currentOwner);
}

bool MakeContact::fPlay(Player *player)
{
	if (player->handSize() == 1)
		return true & ActionCard::fPlay(player);

	return false;
}

void MakeContact::destroy()
{
	ActionCard::destroy();
	UpdateVisibilityFlags flags;
	flags.fOwner = true;
	_selection->update(&flags);
}
