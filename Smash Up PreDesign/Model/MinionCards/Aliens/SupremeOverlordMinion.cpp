#include "SupremeOverlordMinion.h"
#include <Board.h>
#include <Player.h>

SupremeOverlordMinion::SupremeOverlordMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "Supreme Overlord";
	_faction = ALIEN;
}

void SupremeOverlordMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	std::vector<MinionCard *> minions = vBoard->minionsInPlay();
	MinionCard *selection = card->currentOwner()->selectCard(minions);
	selection->returnToOwnersHand();
}
