#include "LendHandAction.h"
#include <Player.h>

LendHandAction::LendHandAction(Player *owner) : ActionCard(owner)
{
	_name = "Lend a Hand";
	_cardType = INSTANT_CARD;
}

void LendHandAction::play()
{
	ActionCard::play();

	std::vector<Card *> selection = _currentOwner->selectCards(_currentOwner->deck(), INT_MAX, true);
	std::vector<Card *>::iterator itCards;

	for (itCards = selection.begin(); itCards != selection.end(); itCards++)
	{
		Card *toAdd = _currentOwner->removeFromDiscard((*itCards)->name());
		_currentOwner->addCardToDeck(toAdd);
	}

	_currentOwner->shuffleDeck(false);
}