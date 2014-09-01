#include "CellularBonding.h"
#include <Player.h>
#include <Board.h>

CellularBonding::CellularBonding(Player *owner) : ActionCard(owner)
{
	this->_name = "Shell Game";
	_cardType = MINION_CARD;
	_copiedCard = NULL;
}

ActionCard * CellularBonding::copy()
{
	return new CellularBonding(_currentOwner);
}

void CellularBonding::play(MinionCard *minion, ActionCard *action)
{
	ActionCard *selection = action->currentOwner()->selectCard(vBoard->actionsOnMinions());
	_copiedCard = selection->copy();
	_copiedCard->setCurrentOwner(action->currentOwner());
	_copiedCard->play(minion,action); // When it calls it's super action::play it won't actually add it too the minion because this != action
	ActionCard::play(minion, action);
}

bool CellularBonding::fUpdate(UpdateVisibilityFlags *flags)
{
	return _copiedCard->fUpdate(flags);
}

void CellularBonding::update(MinionCard *minion)
{
	_copiedCard->update(minion);
}

void CellularBonding::destroy()
{
	//TODO destroy will probably need a reference to the action it is destorying to know if it should really remove itselft the the minion
	_copiedCard->destroy();
	delete(_copiedCard);
	ActionCard::destroy();
}