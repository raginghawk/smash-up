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

	Card *toAdd = _currentOwner->removeFromDiscard(selection->name()); 
	_currentOwner->addCardToHand(toAdd);
}