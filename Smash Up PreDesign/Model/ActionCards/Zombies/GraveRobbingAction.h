#pragma once

#include <ActionCard.h>

class GraveRobbingAction : public ActionCard
{
public:
	GraveRobbingAction(Player *owner);
	virtual void play();
};