#include "BuccaneerMinion.h"
#include <Player.h>
#include <Board.h>

BuccaneerMinion::BuccaneerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 4;
	_name = "Buccaneer";
	_faction = PIRATE;
}

bool BuccaneerMinion::destroy(MinionCard *card)
{
	if (card->fDestroyable())
	{
		card->move(card->currentOwner()->selectBase(vBoard->otherBases(card->base())));
	}
	return false;
}
