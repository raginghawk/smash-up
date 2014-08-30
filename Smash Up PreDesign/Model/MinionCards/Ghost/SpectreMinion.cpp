#include "SpectreMinion.h"
#include <Player.h>

SpectreMinion::SpectreMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "Spectre";
}

void SpectreMinion::discard()
{
	MinionCard::discard();
	_owner->addMinionToPlayableDiscards(this);
}
