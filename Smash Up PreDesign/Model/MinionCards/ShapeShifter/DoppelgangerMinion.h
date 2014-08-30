#pragma once

#include <MinionCard.h>

class DoppelgangerMinion : public MinionCard
{
public:
	DoppelgangerMinion::DoppelgangerMinion(Player *owner);
	virtual void destroy(Player *owner);
};