#pragma once

#include <MinionCard.h>

class PolarCommandoMinion : public MinionCard
{
public:
	PolarCommandoMinion(Player *owner);
	virtual bool fDestoryable(MinionCard *card);
	virtual int currentPower(MinionCard *card);
};