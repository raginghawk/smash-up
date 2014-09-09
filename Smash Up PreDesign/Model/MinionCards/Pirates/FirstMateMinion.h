#pragma once

#include <MinionCard.h>
#include <EventListener.h>

class FirstMateMinion : public MinionCard, public EventListener
{
public:
	FirstMateMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
	virtual void discard();
	virtual void move(Base *newBase);
	//EventListener
	virtual void call(EventData *eventData);
};