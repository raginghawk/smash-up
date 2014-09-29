#pragma once

#include <ActionCard.h>

class ComingToYouAction : public ActionCard
{
public:
	ComingToYouAction(Player *owner);
	virtual void play(Base *base);
	virtual void discard();
};