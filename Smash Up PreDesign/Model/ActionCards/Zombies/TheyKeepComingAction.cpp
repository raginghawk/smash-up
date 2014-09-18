#include "TheyKeepComingAction.h"
#include <Player.h>
#include <Board.h>
#include <MinionCard.h>

TheyKeepComingAction::TheyKeepComingAction(Player *owner) : ActionCard(owner)
{
	_name = "They Keep Coming";
	_cardType = INSTANT_CARD;
}

void TheyKeepComingAction::play()
{
	ActionCard::play();

	MinionCard *minionSelection = _currentOwner->minionInDiscard(INT_MAX);
	Base *baseSelection = _currentOwner->selectBase(vBoard->bases());

	minionSelection->play(baseSelection);
}