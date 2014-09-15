#pragma once

#include <ActionCard.h>

class SeaDogsAction : public ActionCard
{
public:
	SeaDogsAction(Player *owner);
	virtual void play();
};