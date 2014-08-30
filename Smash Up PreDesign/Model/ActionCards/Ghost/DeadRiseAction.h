#pragma once

#include <ActionCard.h>

class DeadRiseAction : public ActionCard
{
public:
	DeadRiseAction::DeadRiseAction(Player *owner);
	virtual void play();
};