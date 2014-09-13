#include "BuccaneerMinion.h"
#include <Player.h>
#include <Board.h>

BuccaneerMinion::BuccaneerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 4;
	_name = "Buccaneer";
}

bool BuccaneerMinion::destroy(MinionCard *card)
{
	if (card->fDestoryable())
	{
		card->move(card->currentOwner()->selectBase(vBoard->otherBases(card->base())));
	}
	return false;
}
