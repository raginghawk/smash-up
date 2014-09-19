#include "OutbreakAction.h"
#include <Player.h>
#include <Board.h>
#include <Base.h>
#include <MinionCard.h>

OutbreakAction::OutbreakAction(Player *owner) : ActionCard(owner)
{
	_name = "Outbreak";
	_cardType = INSTANT_CARD;
}

void OutbreakAction::play()
{
	ActionCard::play();

	std::vector<Base *> bases = vBoard->bases();
	std::vector<Base *> baseOptions;
	std::vector<Base *>::iterator itBases;

	for (itBases = bases.begin(); itBases != bases.end(); itBases++)
	{
		if ((*itBases)->minionsFromPlayer(_currentOwner).size() == 0)
		{
			baseOptions.push_back(*itBases);
		}
	}

	if (baseOptions.begin() == baseOptions.end())
		return;

	Base * baseSelection = _currentOwner->selectBase(baseOptions);
	MinionCard *minionSelection = _currentOwner->selectCard(_currentOwner->minionsInHand());
	
	minionSelection->play(baseSelection);
}