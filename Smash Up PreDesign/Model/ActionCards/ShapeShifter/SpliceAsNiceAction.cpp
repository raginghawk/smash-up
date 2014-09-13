#include "SpliceAsNiceAction.h"
#include <MinionCard.h>

SpliceAsNiceAction::SpliceAsNiceAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Splice as Nice";
	_cardType = MINION_CARD;
	_minion = NULL;
}

void SpliceAsNiceAction::play(MinionCard *minion)
{
	_minion = minion;
	minion->modifyCurrentPower(2);
}

bool SpliceAsNiceAction::destroy()
{
	_minion->modifyCurrentPower(-2);
	return ActionCard::destroy();
}