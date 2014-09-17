#include "WalkerMinion.h"
#include <Player.h>

WalkerMinion::WalkerMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "Walker";
	_faction = ZOMBIE;
}

void WalkerMinion::play(Base *base, MinionCard *card)
{
	card->currentOwner()->lookAtTopCard();
	//TODO select choice 
	bool choice = true;
	if (choice)
		card->currentOwner()->discardTopCard();

	MinionCard::play(base, card);
}