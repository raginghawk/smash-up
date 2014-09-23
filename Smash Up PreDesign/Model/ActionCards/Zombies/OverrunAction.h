#pragma once

#include <ActionCard.h>
#include <EventListener.h>

class OverrunAction : public ActionCard, public EventListener
{
public:
	OverrunAction(Player *owner);
	virtual void play(Base *base);
	virtual void discard();

	//EventListener
	virtual void call(EventData *eventData);
};