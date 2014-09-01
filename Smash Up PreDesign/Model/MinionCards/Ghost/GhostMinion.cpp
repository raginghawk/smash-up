#include "GhostMinion.h"
#include <Player.h>

GhostMinion::GhostMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "Ghost";
}

void GhostMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	card->currentOwner()->discardCard(1, true);
}
