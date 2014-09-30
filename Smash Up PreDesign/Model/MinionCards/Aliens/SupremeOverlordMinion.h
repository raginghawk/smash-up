#pragma once

#include <MinionCard.h>

class SupremeOverlordMinion : public MinionCard
{
public:
	SupremeOverlordMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};