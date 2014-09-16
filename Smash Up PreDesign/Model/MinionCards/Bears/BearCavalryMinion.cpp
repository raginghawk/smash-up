#include "BearCavalryMinion.h"
#include <Player.h>
#include <Base.h>
#include <Board.h>

BearCavalryMinion::BearCavalryMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 3;
	_name = "Bear Cavalry";
	_faction = BEAR_CAVALRY;
}

void BearCavalryMinion::play(Base *base, MinionCard *card)
{
	std::vector<MinionCard *> minionOptions = base->otherPlayersMinions(card->currentOwner());
	MinionCard * minionSelection = card->currentOwner()->selectCard(minionOptions);
	Base * baseSelection = card->currentOwner()->selectBase(vBoard->otherBases(base));

	minionSelection->move(baseSelection);
	MinionCard::play(base, card);
}