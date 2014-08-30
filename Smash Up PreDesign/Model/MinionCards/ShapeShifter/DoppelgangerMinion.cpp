#include "DoppelgangerMinion.h"
#include <Player.h>

DoppelgangerMinion::DoppelgangerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 0;
	_name = "Mimic";
}

void DoppelgangerMinion::destroy(Player *owner)
{
	MinionCard *selection = owner->minionInDeck(INT_MAX);

	if (!selection)
		return;

	selection->play(_base);
	owner->shuffleDeck(false);
}
