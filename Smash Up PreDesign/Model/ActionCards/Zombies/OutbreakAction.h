#pragma once

#include <ActionCard.h>

class OutbreakAction : public ActionCard
{
public:
	OutbreakAction(Player *owner);
	virtual void play();
};