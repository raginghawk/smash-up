#pragma once

#include <ActionCard.h>

class SpliceAsNiceAction : public ActionCard
{
public:
	SpliceAsNiceAction(Player *owner);
	virtual void play(MinionCard *minion);
	virtual bool destroy();
private:
	MinionCard *_minion;
};