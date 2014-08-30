#include "DoppelgangerMinion.h"
#include <Player.h>

DoppelgangerMinion::DoppelgangerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "DoppelGanger";
}

void DoppelgangerMinion::destroy(Player *owner)
{
	MinionCard *selection = owner->minionInDeck(INT_MAX);

	if (!selection)
		return;

	selection->play(_base);
	owner->shuffleDeck(false);
}
