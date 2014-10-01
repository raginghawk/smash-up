#include "CollectorMinion.h"
#include <Base.h>
#include <Player.h>

CollectorMinion::CollectorMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "Collector";
	_faction = ALIEN;
}

void CollectorMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	std::vector<MinionCard *> minions = MinionCard::minionsWithPowerLessThan(4,base->minionsOnBase());
	MinionCard *selection = card->currentOwner()->selectCard(minions);
	selection->returnToOwnersHand();
}
