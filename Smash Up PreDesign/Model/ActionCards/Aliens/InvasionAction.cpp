#include "InvasionAction.h"
#include <Player.h>
#include <MinionCard.h>
#include <Board.h>

InvasionAction::InvasionAction(Player *owner) : ActionCard(owner)
{
	_name = "Invasion";
	_cardType = INSTANT_CARD;
}

void InvasionAction::play()
{
	ActionCard::play();

	MinionCard *minionSelection = _currentOwner->selectCard(vBoard->minionsInPlay());
	Base *baseSelection = _currentOwner->selectBase(vBoard->bases());
	minionSelection->move(baseSelection);
}