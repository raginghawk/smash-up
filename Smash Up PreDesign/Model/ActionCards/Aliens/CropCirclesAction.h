#pragma once

#include <ActionCard.h>

class CropCirclesAction : public ActionCard
{
public:
	CropCirclesAction(Player *owner);
	virtual void play();
};