#include "BroadsideAction.h"
#include <Board.h>
#include <Base.h>
#include <Player.h>
#include <MinionCard.h>

BroadsideAction::BroadsideAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Broadside";
	_cardType = INSTANT_CARD;
}

void BroadsideAction::play()
{
	std::vector<Base *> baseOptions = vBoard->basesWithMinionFromPlayer(_currentOwner);
	if (baseOptions.size() == 0)
		return;
	
	Base * baseSelection = _currentOwner->selectBase(baseOptions);
	Player *playerSelection = _currentOwner->selectPlayer(vBoard->players());

	std::vector<MinionCard *> minionsToDestory = baseSelection->minionsFromPlayerWithPowerLessThan(playerSelection, 3);
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minionsToDestory.begin(); itMinions != minionsToDestory.end(); itMinions++)
	{
		(*itMinions)->destroy();
	}
}