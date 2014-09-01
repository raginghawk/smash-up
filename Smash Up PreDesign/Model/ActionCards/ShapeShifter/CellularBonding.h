#pragma once

#include <ActionCard.h>

class CellularBonding : public ActionCard
{
public:
	CellularBonding(Player *owner);
	virtual void play(MinionCard *minion, ActionCard *action);
	virtual bool fUpdate(UpdateVisibilityFlags *flags);
	virtual void update(MinionCard *minion);
	virtual void destroy();
	virtual ActionCard *copy();
private:
	ActionCard *_copiedCard;
};