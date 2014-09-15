#include "ShanghaiAction.h"
#include <Board.h>
#include <Player.h>
#include <MinionCard.h>

ShanghaiAction::ShanghaiAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Shanghai";
	_cardType = INSTANT_CARD;
}

void ShanghaiAction::play()
{
	std::vector<MinionCard *> minionOptions = vBoard->otherPlayersMinionsInPlay(_currentOwner);

	if (minionOptions.size() == 0)
		return;

	MinionCard *selection = _currentOwner->selectCard(minionOptions);
	Base *newBase = _currentOwner->selectBase(vBoard->otherBases(selection->base()));
	selection->move(newBase);
}