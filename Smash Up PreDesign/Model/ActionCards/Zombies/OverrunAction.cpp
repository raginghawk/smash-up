#include "OverrunAction.h"
#include <Base.h>
#include <Player.h>
#include <Event.h>


OverrunAction::OverrunAction(Player *owner) : ActionCard(owner)
{
	_name = "Overrun";
	_cardType = BASE_CARD;
}

void OverrunAction::play(Base *base)
{
	ActionCard::play(base);

	_base->setPlayableMinionForOtherPlayers(_currentOwner, false);
	_currentOwner->beginingOfTurn()->registerListener(this);
}

void OverrunAction::discard()
{
	_base->setPlayableMinionForOtherPlayers(_currentOwner, true);
	_currentOwner->beginingOfTurn()->unregisterListener(this);
	ActionCard::discard();
}

//EventListener
void OverrunAction::call(EventData *eventData)
{
	assert(eventData->eventType() == BEGINING_OF_TURN);
	this->destroy();
}
