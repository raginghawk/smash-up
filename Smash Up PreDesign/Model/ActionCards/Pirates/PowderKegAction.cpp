#include "PowderKegAction.h"
#include <Board.h>
#include <Player.h>
#include <Base.h>
#include <MinionCard.h>

PowderKegAction::PowderKegAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Powderkeg";
	_cardType = INSTANT_CARD;
}

void PowderKegAction::play()
{
	std::vector<MinionCard *> minionOptions = vBoard->playersMinionsInPlay(_currentOwner);
	if (minionOptions.size() == 0)
		return;

	MinionCard *selection = _currentOwner->selectCard(minionOptions);
	int power = selection->currentPower();
	Base * base = selection->base();

	std::vector<MinionCard *> minionsToDestory = base->minionsWithPowerLessThan(power + 1);
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minionsToDestory.begin(); itMinions != minionsToDestory.end(); itMinions++)
	{
		(*itMinions)->destroy();
	}
}