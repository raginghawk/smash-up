#pragma once

#include <ActionCard.h>

class ReallyAction : public ActionCard
{
public:
	ReallyAction(Player *owner);
	virtual void play();
};