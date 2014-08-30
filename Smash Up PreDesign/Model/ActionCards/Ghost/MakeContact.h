#pragma once

#include <ActionCard.h>

class MakeContact : public ActionCard
{
public:
	MakeContact::MakeContact(Player *owner);
	virtual bool fUpdate(UpdateVisibilityFlags *flags);
	virtual void update(MinionCard *minionCard);
};