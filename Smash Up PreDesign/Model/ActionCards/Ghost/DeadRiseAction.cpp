#pragma once
#include "DeadRiseAction.h"
#include <Player.h>
#include <MinionCard.h>

DeadRiseAction::DeadRiseAction(Player *owner) : ActionCard(owner)
{
	_name = "The Dead Rises";
	_cardType = INSTANT_CARD;
}

void DeadRiseAction::play()
{
	ActionCard::play();

	std::vector<Card *> cardsToDiscard = _currentOwner->selectCards(_currentOwner->hand(), _currentOwner->handSize(), true);
	std::vector<Card *>::iterator itCards;

	for (itCards = cardsToDiscard.begin(); itCards != cardsToDiscard.end(); itCards++)
	{
		_currentOwner->removeCardFromHand(*itCards);
		_currentOwner->addCardToDiscardPile(*itCards);
	}
	
	MinionCard *selection = _currentOwner->minionInDiscard(cardsToDiscard.size()-1, false);
	if (selection)
	{
			Base *base = _currentOwner->selectBase(_currentOwner->baseOptions(selection));
			selection->play(base);
	}
}