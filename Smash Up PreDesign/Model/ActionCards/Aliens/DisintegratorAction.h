#pragma once

#include <ActionCard.h>

class DisintegratorAction : public ActionCard
{
public:
	DisintegratorAction(Player *owner);
	virtual void play();
};