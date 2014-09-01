#pragma once

#include <ActionCard.h>
#include <EventListener.h>

class GeneticShift : public ActionCard, public EventListener
{
public:
	GeneticShift(Player *owner);
	virtual void play();

	//EventListener
	virtual void call();

private:
	MinionCard *_selection;
};