#pragma once

#include <MinionCard.h>

class SaucyWenchMinion : public MinionCard
{
public:
	SaucyWenchMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};