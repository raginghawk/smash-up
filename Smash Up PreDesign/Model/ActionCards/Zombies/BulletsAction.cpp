#include "BulletsAction.h"
#include <Player.h>

BulletsAction::BulletsAction(Player *owner) : ActionCard(owner)
{
	_name = "Not Enough Bullets";
	_cardType = INSTANT_CARD;
}

void BulletsAction::play()
{
	ActionCard::play();

	Card *selection = _currentOwner->selectCard(_currentOwner->discards());

	while (true)
	{
		//TODO add bail out possibly use multi select :)
		Card *toAdd = _currentOwner->removeFromDiscard(selection->name());
		if (toAdd)
		{
			_currentOwner->addCardToHand(toAdd);
		}
		else
			break;
	}
}