#pragma once

#include <MinionCard.h>

class WalkerMinion : public MinionCard
{
public:
	WalkerMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};