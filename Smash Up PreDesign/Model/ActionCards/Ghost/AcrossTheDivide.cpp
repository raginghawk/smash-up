//TODO Chose a card name. Place any number of minions with that name from your discard pile into your hand
#pragma once
#include "AcrossTheDivide.h"
#include <MinionCard.h>
#include <Player.h>

AcrossTheDivide::AcrossTheDivide(Player *owner) : ActionCard(owner)
{
	_name = "Across The Divide";
	_cardType = INSTANT_CARD;
}

void AcrossTheDivide::play()
{
	ActionCard::play();
	MinionCard *selection= _currentOwner->minionInDiscard(INT_MAX, true);

	if (selection)
	{
		Card *minion = _currentOwner->removeFromDiscard(selection);
		while (minion)
		{
			_currentOwner->addCardToHand(minion);
			//TODO add a bail option
		}
	}
}