#include "IncorporealAction.h"
#include <Board.h>
#include <MinionCard.h>

IncorporealAction::IncorporealAction(Player *owner) : ActionCard(owner)
{
	_name = "Incorporeal";
	_cardType = MINION_CARD;
}

//TODO some how mark what it does when it is queried, probably around flags