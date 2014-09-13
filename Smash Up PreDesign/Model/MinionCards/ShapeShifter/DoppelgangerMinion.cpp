#include "DoppelgangerMinion.h"
#include <Player.h>

DoppelgangerMinion::DoppelgangerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "DoppelGanger";
}

bool DoppelgangerMinion::destroy(MinionCard *card)
{
	MinionCard *selection = card->currentOwner()->minionInDeck(INT_MAX);

	if (!selection)
		return MinionCard::destroy(card);

	selection->play(_base);
	card->currentOwner()->shuffleDeck(false);

	return MinionCard::destroy(card);
	//TODO switch to discard (cause the card says discard from a base)
}
