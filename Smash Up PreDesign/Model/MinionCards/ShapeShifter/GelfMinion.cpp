#include "GelfMinion.h"
#include <Player.h>

GelfMinion::GelfMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 0;
	_name = "Mimic";
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
