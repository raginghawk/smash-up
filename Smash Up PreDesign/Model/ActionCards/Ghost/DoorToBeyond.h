#pragma once

#include <ActionCard.h>

class DoorToBeyond : public ActionCard
{
public:
	DoorToBeyond::DoorToBeyond(Player *owner);
	virtual int powerModification(Player *player);

private:
	bool _active;
};