#pragma once

#include <ActionCard.h>

class BeamUpAction : public ActionCard
{
public:
	BeamUpAction(Player *owner);
	virtual void play();
};