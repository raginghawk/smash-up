#pragma once

#include <MinionCard.h>

class BuccaneerMinion : public MinionCard
{
public:
	BuccaneerMinion(Player *owner);
	virtual bool destroy(MinionCard *card);
};