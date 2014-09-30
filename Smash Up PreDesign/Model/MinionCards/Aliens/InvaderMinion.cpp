#include "InvaderMinion.h"
#include <Player.h>

InvaderMinion::InvaderMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 3;
	_name = "Invader";
	_faction = ALIEN;
}

void InvaderMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	card->currentOwner()->addVictoryPoint(1);
}
