#include "GelfMinion.h"
#include <Player.h>

GelfMinion::GelfMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 4;
	_talent = true;
	_name = "G.E.L.F";
	_faction = SHAPE_SHIFTER;
}

void GelfMinion::useTalent(Player *owner, MinionCard *card)
{
	MinionCard *selection = owner->minionInDeck(4);
	owner->shuffleMinionInDeck(card);

	if (!selection)
		return;

	selection->play(card->base());
}
