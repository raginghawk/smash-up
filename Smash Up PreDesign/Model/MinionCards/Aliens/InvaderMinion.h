#pragma once

#include <MinionCard.h>

class InvaderMinion : public MinionCard
{
public:
	InvaderMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};