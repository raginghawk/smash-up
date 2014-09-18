#pragma once

#include <ActionCard.h>

class TheyKeepComingAction : public ActionCard
{
public:
	TheyKeepComingAction(Player *owner);
	virtual void play();
};