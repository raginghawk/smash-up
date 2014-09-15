#include "MimicMinion.h"
#include <Player.h>
#include <Board.h>

MimicMinion::MimicMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 0;
	_name = "Mimic";
	_faction = SHAPE_SHIFTER;
}

int MimicMinion::currentPower(MinionCard *card)
{
	int currentPower = MinionCard::currentPower(card);

	if (card != this)
		currentPower -= 2; /*Copycat modifier*/

	std::vector<MinionCard *> minionsInPlay = vBoard->minionsInPlay();
	std::vector<MinionCard *>::iterator itMinions;

	int maxPower = 0;
	for (itMinions = minionsInPlay.begin(); itMinions != minionsInPlay.end(); itMinions++)
	{
		if ((*itMinions)->printedPower() > maxPower)
		{
			maxPower = (*itMinions)->printedPower();
		}
	}

	return currentPower + maxPower;
}