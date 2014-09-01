#include "DoppelgangerMinion.h"
#include <Player.h>

DoppelgangerMinion::DoppelgangerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "DoppelGanger";
}

void DoppelgangerMinion::destroy(MinionCard *card)
{
	MinionCard *selection = card->currentOwner()->minionInDeck(INT_MAX);

	if (!selection)
		return;

	selection->play(_base);
	card->currentOwner()->shuffleDeck(false);
}
