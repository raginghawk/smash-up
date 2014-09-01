#include "MitosisAction.h"
#include <Player.h>
#include <Board.h>
#include <MinionCard.h>

MitosisAction::MitosisAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Mitosis";
	_cardType = INSTANT_CARD;
}

void MitosisAction::play()
{
	MinionCard *selection = _currentOwner->selectCard(vBoard->playersMinionsInPlay(_currentOwner));
	std::vector<MinionCard *>::iterator itMinions;
	std::vector<MinionCard *> minionsInHand = _currentOwner->minionsInHand();

	for (itMinions = minionsInHand.begin(); itMinions != minionsInHand.end(); itMinions++)
	{
		if (!strcmp(selection->name().c_str(), (*itMinions)->name().c_str()))
		{
			(*itMinions)->play(_currentOwner->selectBase());
			return;
		}
	}
}