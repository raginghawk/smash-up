#include "GeneralIvanMinion.h"
#include <Player.h>

GeneralIvanMinion::GeneralIvanMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 6;
	_name = "General Ivan";
	_faction = BEAR_CAVALRY;
}

void GeneralIvanMinion::play(Base *base, MinionCard *minion)
{
	minion->currentOwner()->incrementDestroyableCount(1);
	MinionCard::play(base, minion);
}

void GeneralIvanMinion::discard(MinionCard *minion)
{
	minion->currentOwner()->incrementDestroyableCount(-1);
	MinionCard::discard(minion);
}
