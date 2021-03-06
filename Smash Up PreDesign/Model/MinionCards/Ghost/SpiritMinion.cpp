#include "SpiritMinion.h"
#include <Player.h>
#include <Board.h>

SpiritMinion::SpiritMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 3;
	_name = "Spirit";
	_faction = GHOST;
}

void SpiritMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);

	std::vector<MinionCard *> minionsInPlay = vBoard->minionsInPlay();
	if (minionsInPlay.size() == 0)
		return;
	while (true)
	{
		MinionCard *selection = card->currentOwner()->selectCard(minionsInPlay);

		if (card->currentOwner()->discardCard(selection->currentPower(selection), true))
		{
			selection->destroy();
		}
	}
}
