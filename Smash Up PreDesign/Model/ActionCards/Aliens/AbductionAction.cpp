#include "AbductionAction.h"
#include <Player.h>
#include <MinionCard.h>
#include <Board.h>

AbductionAction::AbductionAction(Player *owner) : ActionCard(owner)
{
	_name = "Abduction";
	_cardType = INSTANT_CARD;
}

void AbductionAction::play()
{
	ActionCard::play();

	MinionCard *selection = _currentOwner->selectCard(vBoard->minionsInPlay());
	selection->returnToOwnersHand();
	_currentOwner->addMinionCount(INT_MAX, NULL);
}