#include "HauntingMinion.h"
#include <Player.h>

HauntingMinion::HauntingMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 3;
	_name = "Haunting";
}

int HauntingMinion::currentPower()
{
	int currentPower = MinionCard::currentPower();
	if (_currentOwner->handSize() < 3)
	{
		currentPower += 3;
	}
	return currentPower;
}

bool HauntingMinion::isAffectable()
{
	if (_currentOwner->handSize() < 3)
	{
		return false;
	}
	return MinionCard::isAffectable();
}