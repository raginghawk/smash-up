#pragma once

#include "ActionCard.h"

class GhostlyAction : public ActionCard
{
public:
	GhostlyAction::GhostlyAction(Player *owner);
	virtual void play();
};