#pragma once

#include <MinionCard.h>

class GeneralIvanMinion : public MinionCard
{
public:
	GeneralIvanMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
	virtual void discard(MinionCard *minion);
};