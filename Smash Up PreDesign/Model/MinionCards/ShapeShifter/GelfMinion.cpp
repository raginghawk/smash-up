#include "GelfMinion.h"
#include <Player.h>

GelfMinion::GelfMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 4;
	_name = "G.E.L.F";
	_talent = true;
}

void GelfMinion::useTalent(Player *owner)
{
	MinionCard *selection = owner->minionInDeck(4);
	owner->shuffleMinionInDeck(this);

	if (!selection)
		return;

	selection->play(_base);
}
