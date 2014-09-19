#pragma once

#include <ActionCard.h>

class LendHandAction : public ActionCard
{
public:
	LendHandAction(Player *owner);
	virtual void play();
};