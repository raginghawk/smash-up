#include "PolarCommandoMinion.h"
#include <Base.h>

PolarCommandoMinion::PolarCommandoMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 4;
	_name = "Polar Commando";
	_faction = BEAR_CAVALRY;
}

bool PolarCommandoMinion::fDestoryable(MinionCard *card)
{
	if (card->base()->minionsFromPlayer(card->currentOwner()).size() == 0)
		return false;

	else return MinionCard::fDestroyable(card);
}

int PolarCommandoMinion::currentPower(MinionCard *card)
{
	int currentPower = MinionCard::currentPower(card);

	if (card->base()->minionsFromPlayer(card->currentOwner()).size() == 0)
		currentPower += 2;
	
	return currentPower;
}