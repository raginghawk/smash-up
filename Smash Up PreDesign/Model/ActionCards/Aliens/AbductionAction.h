#pragma once

#include <ActionCard.h>

class AbductionAction : public ActionCard
{
public:
	AbductionAction(Player *owner);
	virtual void play();
};