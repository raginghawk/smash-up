#pragma once

#include <ActionCard.h>

class BroadsideAction : public ActionCard
{
public:
	BroadsideAction(Player *owner);
	virtual void play();
};