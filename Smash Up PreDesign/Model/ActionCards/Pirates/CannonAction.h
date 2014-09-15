#pragma once

#include <ActionCard.h>

class CannonAction : public ActionCard
{
public:
	CannonAction(Player *owner);
	virtual void play();
};