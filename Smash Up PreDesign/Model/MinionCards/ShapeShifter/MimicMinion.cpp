#include "MimicMinion.h"
#include <Player.h>
#include <Board.h>

MimicMinion::MimicMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 0;
	_name = "Mimic";
}

int MimicMinion::currentPower()
{
	int currentPower = MinionCard::currentPower();

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