#include "GelfMinion.h"
#include <Player.h>
#include <Base.h>

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

	card->removeAllActions();
	_base->removeCard(card);
	owner->shuffleMinionInDeck(card);

	if (!selection)
		return;

	selection->play(card->base());
}
