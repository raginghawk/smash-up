#include "DoorToBeyond.h"
#include "Base.h"
#include <Player.h>

DoorToBeyond::DoorToBeyond(Player *owner) : ActionCard(owner)
{
	this->_name = "The Door to The Beyond";
	_cardType = BASE_CARD;
	_active = false;
}

bool DoorToBeyond::fUpdate(UpdateVisibilityFlags *flags)
{
	return flags->fPower;
}

void DoorToBeyond::update(Base *base)
{
	if (_currentOwner->handSize() < 3 && !_active)
	{
		base->modifyPower(2, _currentOwner);
		_active = true;
	}
	else if (_currentOwner->handSize() > 2 && _active)
	{
		base->modifyPower(-2, _currentOwner);
		_active = false;
	}
}
