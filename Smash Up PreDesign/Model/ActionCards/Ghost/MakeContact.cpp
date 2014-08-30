//TODO Steal minion :/
#pragma once
#include "MakeContact.h"
#include <MinionCard.h>

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
