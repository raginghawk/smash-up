#include "BeamUpAction.h"
#include <Player.h>
#include <MinionCard.h>
#include <Board.h>

BeamUpAction::BeamUpAction(Player *owner) : ActionCard(owner)
{
	_name = "Beam Up";
	_cardType = INSTANT_CARD;
}

void BeamUpAction::play()
{
	ActionCard::play();

	MinionCard *selection = _currentOwner->selectCard(vBoard->minionsInPlay());
	selection->returnToOwnersHand();
}