#include "HauntingMinion.h"
#include <Player.h>

HauntingMinion::HauntingMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 3;
	_name = "Haunting";
	_faction = GHOST;
}

int HauntingMinion::currentPower(MinionCard *card)
{
	int currentPower = MinionCard::currentPower(card);
	if (card->currentOwner()->handSize() < 3)
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