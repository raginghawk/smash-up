#pragma once

#include <ActionCard.h>

class CellularBonding : public ActionCard
{
public:
	CellularBonding(Player *owner);
	virtual void play(MinionCard *minion, ActionCard *action);
	virtual bool destroy();
	//TODO add powerModification()
	virtual ActionCard *copy();
private:
	ActionCard *_copiedCard;
};