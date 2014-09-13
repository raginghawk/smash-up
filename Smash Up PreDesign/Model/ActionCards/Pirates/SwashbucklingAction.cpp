#include "SwashbucklingAction.h"
#include <Player.h>
#include <Event.h>

SwashbucklingAction::SwashbucklingAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Swashbuckling";
	_cardType = INSTANT_CARD;
}

void SwashbucklingAction::play()
{
	_currentOwner->endOfTurn()->registerListener(this);
	_currentOwner->modifyMinionPower(1);
}

void SwashbucklingAction::call(EventData *eventData)
{
	assert(eventData->eventType() == END_OF_TURN);
	_currentOwner->modifyMinionPower(-1);
	_currentOwner->endOfTurn()->unregisterListener(this);
}