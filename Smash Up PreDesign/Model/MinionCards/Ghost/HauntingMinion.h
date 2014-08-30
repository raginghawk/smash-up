#pragma once

#include <MinionCard.h>

class HauntingMinion : public MinionCard
{
public:
	HauntingMinion::HauntingMinion(Player *owner);
	virtual int currentPower();
	virtual bool isAffectable();
};