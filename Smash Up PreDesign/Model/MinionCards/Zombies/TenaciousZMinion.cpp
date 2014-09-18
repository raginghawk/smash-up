#include "TenaciousZMinion.h"
#include <Player.h>

TenaciousZMinion::TenaciousZMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "Tenacious Z";
	_faction = ZOMBIE;
}

void TenaciousZMinion::play(Base *base, MinionCard *card)
{
	if (card == this) // Copycat can't steal this because when it gets discarded it loses the special
	{
		if (!this->owner()->isCardInHand(this)) // aka it is being played from the discards
		{
			assert(!this->owner()->playedTenaciousZ);
			this->owner()->playedTenaciousZ = true;
		}
	}

	MinionCard::play(base, card);
}

void TenaciousZMinion::discard()
{
	MinionCard::discard();
	_owner->addMinionToPlayableDiscards(this);
}

bool TenaciousZMinion::fPlay(Player *player, Base *base)
{
	if (this->owner()->isCardInHand(this))
		return MinionCard::fPlay(player, base);
	else
		return  !(this->owner()->playedTenaciousZ) && MinionCard::fPlay(player, base);
}
