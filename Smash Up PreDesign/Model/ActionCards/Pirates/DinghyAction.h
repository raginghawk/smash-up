#pragma once

#include <ActionCard.h>

class DinghyAction : public ActionCard
{
public:
	DinghyAction(Player *owner);
	virtual void play();
};