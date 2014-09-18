#include "SpectreMinion.h"
#include <Player.h>

SpectreMinion::SpectreMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "Spectre";
	_faction = GHOST;
}

void SpectreMinion::discard()
{
	MinionCard::discard();
	_owner->addMinionToPlayableDiscards(this);
}

bool SpectreMinion::fPlay(Player *player, Base *base)
{
	if (this->owner()->isCardInHand(this))
		return MinionCard::fPlay(player,base);
	else
		return (this->owner()->handSize() < 3) && MinionCard::fPlay(player,base);
}
