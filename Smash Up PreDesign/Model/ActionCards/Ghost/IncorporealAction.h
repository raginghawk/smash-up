#pragma once

#include <ActionCard.h>

class IncorporealAction : public ActionCard
{
public:
	IncorporealAction::IncorporealAction(Player *owner);
	virtual void play(MinionCard *minion, ActionCard *action);
	virtual void destroy();
private:
	MinionCard *_selection;
};