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
		Card *toAdd = card->currentOwner()->removeFromDiscard(selection->name());
		card->currentOwner()->addCardToHand(toAdd);
	}

	MinionCard::play(base, card);
}