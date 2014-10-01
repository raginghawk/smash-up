#include "CropCirclesAction.h"
#include <Player.h>
#include <MinionCard.h>
#include <Board.h>
#include <Base.h>

CropCirclesAction::CropCirclesAction(Player *owner) : ActionCard(owner)
{
	_name = "Crop Circles";
	_cardType = INSTANT_CARD;
}

void CropCirclesAction::play()
{
	ActionCard::play();
	Base * selection = _currentOwner->selectBase(vBoard->bases());
	std::vector<MinionCard *> minions = selection->minionsOnBase();
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minions.begin(); itMinions != minions.end(); itMinions++)
	{
		(*itMinions)->returnToOwnersHand();
	}
}