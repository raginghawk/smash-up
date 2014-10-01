#include "DisintegratorAction.h"
#include <Player.h>
#include <MinionCard.h>
#include <Board.h>

DisintegratorAction::DisintegratorAction(Player *owner) : ActionCard(owner)
{
	_name = "Disintegrator";
	_cardType = INSTANT_CARD;
}

void DisintegratorAction::play()
{
	ActionCard::play();

	MinionCard *selection = _currentOwner->selectCard(MinionCard::minionsWithPowerLessThan(4,vBoard->minionsInPlay()));
	selection->returnToBottomOfDeck();
}