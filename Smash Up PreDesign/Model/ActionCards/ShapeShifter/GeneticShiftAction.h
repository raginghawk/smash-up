#pragma once

#include <ActionCard.h>
#include <EventListener.h>

class GeneticShift : public ActionCard, public EventListener
{
public:
	GeneticShift(Player *owner);
	virtual void play();

	//EventListener
	virtual void call(EventData *eventData);

private:
	MinionCard *_selection;
};