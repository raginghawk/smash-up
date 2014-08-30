#pragma once

#include <MinionCard.h>

class MimicMinion : public MinionCard
{
public:
	MimicMinion::MimicMinion(Player *owner);
	virtual int currentPower();
};