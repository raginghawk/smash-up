#include "ShadyAction.h"
#include <Player.h>

ShadyAction::ShadyAction(Player *owner) : ActionCard(owner)
{
	_name = "Shady Deal";
	_cardType = INSTANT_CARD;
}

void ShadyAction::play()
{
	ActionCard::play();
	
	if (_currentOwner->handSize() < 3)
	{
		_currentOwner->addVictoryPoint(1);
	}
}