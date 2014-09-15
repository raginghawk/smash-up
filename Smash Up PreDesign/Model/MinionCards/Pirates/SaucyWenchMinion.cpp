#include "SaucyWenchMinion.h"
#include <Player.h>
#include <Board.h>

SaucyWenchMinion::SaucyWenchMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 3;
	_name = "Saucy Wench";
	_faction = PIRATE;
}

void SaucyWenchMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);

	std::vector<MinionCard *> minionsOnBase = vBoard->minionsOnBase(card->base());
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minionsOnBase.begin(); itMinions != minionsOnBase.end(); itMinions++)
	{
		if ((*itMinions)->currentPower() > 2)
			minionsOnBase.erase(itMinions);
	}

	if (minionsOnBase.size() == 0)
		return;

	MinionCard *selection = card->currentOwner()->selectCard(minionsOnBase);
	selection->destroy();
}
