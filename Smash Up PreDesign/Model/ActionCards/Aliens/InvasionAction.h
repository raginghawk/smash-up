#pragma once

#include <ActionCard.h>

class InvasionAction : public ActionCard
{
public:
	InvasionAction(Player *owner);
	virtual void play();
};