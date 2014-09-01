#pragma once

#include <ActionCard.h>

class MitosisAction : public ActionCard
{
public:
	MitosisAction(Player *owner);
	virtual void play();
};