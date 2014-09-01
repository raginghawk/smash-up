#include "DoorToBeyond.h"
#include "Base.h"
#include <Player.h>

DoorToBeyond::DoorToBeyond(Player *owner) : ActionCard(owner)
{
	this->_name = "The Door to The Beyond";
	_cardType = BASE_CARD;
}

bool DoorToBeyond::fUpdate(UpdateVisibilityFlags *flags)
{
	return flags->fPower;
}

void DoorToBeyond::update(Base *base)
{
	if (_currentOwner->handSize() < 3)
	{
		base->modifyPower(2,_currentOwner);
	}
}
