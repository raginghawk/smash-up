#pragma once

#include <MinionCard.h>

class ZombieLordMinion : public MinionCard
{
public:
	ZombieLordMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);
};