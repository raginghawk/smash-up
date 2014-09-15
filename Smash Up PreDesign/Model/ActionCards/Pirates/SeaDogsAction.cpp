#include "SeaDogsAction.h"
#include <Board.h>
#include <Player.h>
#include <MinionCard.h>
#include <Base.h>

SeaDogsAction::SeaDogsAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Sea Dogs";
	_cardType = INSTANT_CARD;
}

void SeaDogsAction::play()
{
	Faction factionSelection = _currentOwner->selectFaction();
	Base *baseSelection = _currentOwner->selectBase(vBoard->bases());
	Base *newBase = _currentOwner->selectBase(vBoard->otherBases(baseSelection));

	std::vector<MinionCard *> minions = baseSelection->minionsOfFaction(factionSelection);
	std::vector<MinionCard *>::iterator itMinions;

	for (itMinions = minions.begin(); itMinions != minions.end(); itMinions++)
	{
		if ((*itMinions)->currentOwner() != _currentOwner)
			(*itMinions)->move(newBase);
	}

}