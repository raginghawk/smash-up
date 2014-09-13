#include "IncorporealAction.h"
#include <Board.h>
#include <MinionCard.h>
#include <Player.h>

IncorporealAction::IncorporealAction(Player *owner) : ActionCard(owner)
{
	_name = "Incorporeal";
	_cardType = MINION_CARD;
}

ActionCard * IncorporealAction::copy()
{
	return new IncorporealAction(_currentOwner);
}

void IncorporealAction::play(MinionCard *minion, ActionCard *action)
{
	_selection = action->currentOwner()->selectCard(vBoard->playersMinionsInPlay(action->currentOwner()));
	_selection->modifyAffectAbleCount(1);
	ActionCard::play(minion, action);
}

bool IncorporealAction::destroy()
{
	_selection->modifyAffectAbleCount(-1);
	return ActionCard::destroy();
}
