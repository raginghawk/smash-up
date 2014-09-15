#pragma once

#include <ActionCard.h>

class ShanghaiAction : public ActionCard
{
public:
	ShanghaiAction(Player *owner);
	virtual void play();
};