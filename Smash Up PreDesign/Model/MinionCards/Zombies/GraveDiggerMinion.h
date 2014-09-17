#pragma once

#include <MinionCard.h>

class GraveDiggerMinion : public MinionCard
{
public:
	GraveDiggerMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};