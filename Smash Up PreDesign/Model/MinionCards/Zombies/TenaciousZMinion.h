#pragma once

#include <MinionCard.h>

class TenaciousZMinion : public MinionCard
{
public:
	TenaciousZMinion(Player *owner);
	virtual void discard();
	virtual bool fPlay(Player *player, Base *base);
	virtual void play(Base *base, MinionCard *card);
};