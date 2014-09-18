#pragma once

#include <MinionCard.h>

class SpectreMinion : public MinionCard
{
public:
	SpectreMinion::SpectreMinion(Player *owner);
	virtual void discard();
	virtual bool fPlay(Player *player, Base *base);
};