#pragma once

#include <MinionCard.h>
#include <EventListener.h>

class PirateKingMinion : public MinionCard, public EventListener
{
public:
	PirateKingMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
	virtual void discard(MinionCard *card);
	//EventListener
	virtual void call(EventData *eventData);
};