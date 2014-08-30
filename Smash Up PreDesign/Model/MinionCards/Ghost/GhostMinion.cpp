#include "GhostMinion.h"
#include <Player.h>

GhostMinion::GhostMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "Ghost";
}

void GhostMinion::play(Base *base)
{
	MinionCard::play(base);
	_owner->discardCard(1, true);
}
