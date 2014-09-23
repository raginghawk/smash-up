#include "DoorToBeyond.h"
#include "Base.h"
#include <Player.h>

DoorToBeyond::DoorToBeyond(Player *owner) : ActionCard(owner)
{
	this->_name = "The Door to The Beyond";
	_cardType = BASE_CARD;
	_active = false;
}

int DoorToBeyond::powerModification()
{
	if (_currentOwner->handSize() < 3)
		return 2 + ActionCard::powerModification();
	else
		return ActionCard::powerModification();
}
