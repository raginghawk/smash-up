//Play on a base.Ongoing: On your turn, you may play a minion here from your discard pile instead of from your hand
#include "ComingToYouAction.h"
#include <Base.h>
#include <Player.h>

ComingToYouAction::ComingToYouAction(Player *owner) : ActionCard(owner)
{
	_name = "They're coming to get you";
	_cardType = BASE_CARD;
}

void ComingToYouAction::play(Base *base)
{
	ActionCard::play(base);
	base->setPlaybleFromDiscardForPlayer(_currentOwner, true);
}

void ComingToYouAction::discard()
{
	ActionCard::discard();
	_base->setPlaybleFromDiscardForPlayer(_currentOwner, false);
}
