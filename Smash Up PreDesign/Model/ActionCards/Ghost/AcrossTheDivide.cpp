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
	MinionCard *selection= _currentOwner->minionInDiscard(INT_MAX, false);

	std::vector<Card *> multiSelction = _currentOwner->selectCards(_currentOwner->cardsFromDiscardWithName(selection->name()), INT_MAX, true);
	std::vector<Card *>::iterator itCards;

	for (itCards = multiSelction.begin(); itCards != multiSelction.end(); itCards++)
	{
		Card *minion = _currentOwner->removeFromDiscard(selection->name());
		_currentOwner->addCardToHand(minion);
	}
}