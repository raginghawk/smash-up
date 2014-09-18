#include "GraveRobbingAction.h"
#include <Player.h>

GraveRobbingAction::GraveRobbingAction(Player *owner) : ActionCard(owner)
{
	_name = "Grave Robbing";
	_cardType = INSTANT_CARD;
}

void GraveRobbingAction::play()
{
	ActionCard::play();

	Card *selection = _currentOwner->selectCard(_currentOwner->discards());

	// toAdd is not always = to selection. Because removeFromDiscard removes the first instance (via name matching) and then returns a reference to the card it actually erases
	Card *toAdd = _currentOwner->removeFromDiscard(selection); 
	_currentOwner->addCardToHand(toAdd);
}