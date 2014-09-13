#pragma once

#include <ActionCard.h>
#include <EventListener.h>

class SwashbucklingAction : public ActionCard, public EventListener
{
public:
	SwashbucklingAction(Player *owner);
	virtual void play();

	//EventListener
	virtual void call(EventData *eventData);
};