#pragma once

#include <ActionCard.h>

class ShadyAction : public ActionCard
{
public:
	ShadyAction::ShadyAction(Player *owner);
	virtual void play();
};