#include "GraveDiggerMinion.h"
#include <Player.h>

GraveDiggerMinion::GraveDiggerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 4;
	_name = "Grave Digger";
	_faction = ZOMBIE;
}

void GraveDiggerMinion::play(Base *base, MinionCard *card)
{
	MinionCard *selection = card->currentOwner()->minionInDiscard(INT_MAX, true);

	if (selection)
	{
		bool removed = card->currentOwner()->removeFromDiscard(selection);
		assert(removed);
		card->currentOwner()->addCardToHand(selection);
	}

	MinionCard::play(base, card);
}