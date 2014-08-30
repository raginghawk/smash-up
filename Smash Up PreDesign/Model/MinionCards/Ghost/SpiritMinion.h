#pragma once

#include <MinionCard.h>

class SpiritMinion : public MinionCard
{
public:
	SpiritMinion::SpiritMinion(Player *owner);
	virtual void play(Base *base);
};