#include "ShellGameAction.h"
#include <MinionCard.h>

ShellGameAction::ShellGameAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Shell Game";
	_cardType = MINION_CARD;
	_minion = NULL;
}

void ShellGameAction::play(MinionCard *minion)
{
	_minion = minion;
	minion->modifyDestroyCount(1);
}

bool ShellGameAction::destroy()
{
	_minion->modifyDestroyCount(-1);
	return ActionCard::destroy();
}