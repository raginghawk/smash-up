#include "ZombieLordMinion.h"
#include <Player.h>
#include <Base.h>
#include <Board.h>

ZombieLordMinion::ZombieLordMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "Zombie Lord";
	_faction = ZOMBIE;
}

void ZombieLordMinion::play(Base *base, MinionCard *card)
{
	std::vector<Base *> bases = vBoard->bases();
	std::vector<Base *>::iterator itBases;

	for (itBases = bases.begin(); itBases != bases.end(); itBases++)
	{
		if (base != *itBases && (*itBases)->minionsFromPlayer(card->currentOwner()).size() == 0) //haven't yet played Zombie Lord so you need to exclude this base you will play the Zombie Lord in case it is currently empty
		{ 
			MinionCard *selection = card->currentOwner()->minionInDiscard(2, true);
			if (selection)
			{
				card->currentOwner()->removeFromDiscard(selection->name());
				selection->play(*itBases);
			}
		}
	}

	MinionCard::play(base, card);
}