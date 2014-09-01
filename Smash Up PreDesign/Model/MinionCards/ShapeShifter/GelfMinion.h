#pragma once

#include <MinionCard.h>

class GelfMinion : public MinionCard
{
public:
	GelfMinion::GelfMinion(Player *owner);
	virtual void useTalent(Player *owner, MinionCard *card);
};