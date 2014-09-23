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

ActionCard * MakeContact::copy()
{
	return new MakeContact(_currentOwner);
}

void MakeContact::play(MinionCard *minionCard, ActionCard *action)
{
	//TODO look at this later
	_currentOwner = action->currentOwner();
	_selection = minionCard;
	_selection->setCurrentOwner(_currentOwner);
	ActionCard::play(minionCard, action);
}

bool MakeContact::fPlay(Player *player)
{
	if (player->handSize() == 1)
		return true & ActionCard::fPlay(player);

	return false;
}

bool MakeContact::destroy()
{
	//TODO look at this
	return ActionCard::destroy();
}
