#pragma once

#include <ActionCard.h>

class PowderKegAction : public ActionCard
{
public:
	PowderKegAction(Player *owner);
	virtual void play();
};