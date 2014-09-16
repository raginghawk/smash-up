#pragma once

#include <MinionCard.h>

class BearCavalryMinion : public MinionCard
{
public:
	BearCavalryMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};