#include "DinghyAction.h"
#include <Board.h>
#include <Player.h>
#include <MinionCard.h>

DinghyAction::DinghyAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Dinghy";
	_cardType = INSTANT_CARD;
}

void DinghyAction::play()
{
	std::vector<MinionCard *> minionOptions = vBoard->playersMinionsInPlay(_currentOwner);
	minionOptions.push_back(NULL); // The back out option because of "up to"

	for (int i = 0; i < 2; i++)
	{
		MinionCard *selection = _currentOwner->selectCard(minionOptions);
		if (selection)
		{
			Base *newBase = _currentOwner->selectBase(vBoard->otherBases(selection->base()));
			selection->move(newBase);
		}
		else
			return;
	}
}