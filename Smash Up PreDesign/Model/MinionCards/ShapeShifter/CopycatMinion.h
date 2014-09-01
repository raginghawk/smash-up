#pragma once

#include <MinionCard.h>
#include <EventListener.h>

class CopycatMinion : public MinionCard, public EventListener
{
public:
	CopycatMinion::CopycatMinion(Player *owner);
	virtual void play(Base *base);
	virtual void destroy(MinionCard *card);
	virtual void useTalent(Player *owner, MinionCard *card);

	//Event Listener
	virtual void call(EventType eventType);
private:
	MinionCard *_selectedMinion;
};