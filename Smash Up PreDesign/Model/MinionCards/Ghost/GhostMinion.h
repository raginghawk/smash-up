#pragma once

#include <MinionCard.h>

class GhostMinion : public MinionCard
{
public:
	GhostMinion::GhostMinion(Player *owner);
	virtual void play(Base *base, MinionCard *card);		
};