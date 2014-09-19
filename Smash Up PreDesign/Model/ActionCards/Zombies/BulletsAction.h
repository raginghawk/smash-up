#pragma once

#include <ActionCard.h>

class BulletsAction : public ActionCard
{
public:
	BulletsAction(Player *owner);
	virtual void play();
};