#pragma once

#include <MinionCard.h>

class CollectorMinion : public MinionCard
{
public:
	CollectorMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};