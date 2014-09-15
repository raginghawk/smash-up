#pragma once

#include <ActionCard.h>
#include <EventListener.h>

class FullSailAction : public ActionCard, public EventListener
{
public:
	FullSailAction(Player *owner);
	virtual void play();
	virtual void drawn();
	virtual void discard();

	//EventListner
	virtual void call(EventData *eventData);
};