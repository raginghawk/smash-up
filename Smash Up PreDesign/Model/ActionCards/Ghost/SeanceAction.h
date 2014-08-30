#pragma once

#include <ActionCard.h>

class SeanceAction : public ActionCard
{
public:
	SeanceAction::SeanceAction(Player *owner);
	virtual void play();
};