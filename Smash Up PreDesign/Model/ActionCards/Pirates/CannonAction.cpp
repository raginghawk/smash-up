#include "CannonAction.h"
#include <Board.h>
#include <Player.h>
#include <MinionCard.h>

CannonAction::CannonAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Cannon";
	_cardType = INSTANT_CARD;
}

void CannonAction::play()
{
	std::vector<MinionCard *> minionOptions = vBoard->minionsWithPowerLessThan(3);
	minionOptions.push_back(NULL); // The back out option because of "up to"

	for (int i = 0; i < 2; i++)
	{
		MinionCard *selection = _currentOwner->selectCard(minionOptions);
		if (selection)
		{
			selection->destroy();
		}
		else
			return;
	}
}