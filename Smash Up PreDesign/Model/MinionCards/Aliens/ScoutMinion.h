#pragma once

#include <MinionCard.h>
#include <EventListener.h>

class ScoutMinion : public MinionCard, public EventListener
{
public:
	ScoutMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
	virtual void discard();
	virtual void move(Base *newBase);
	//EventListener
	virtual void call(EventData *eventData);
};