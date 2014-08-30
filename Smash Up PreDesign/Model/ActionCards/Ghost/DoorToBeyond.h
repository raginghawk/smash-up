#pragma once

#include <ActionCard.h>

class DoorToBeyond : public ActionCard
{
public:
	DoorToBeyond::DoorToBeyond(Player *owner);
	virtual bool fUpdate(UpdateVisibilityFlags *flags);
	virtual void update(Base *base);
};