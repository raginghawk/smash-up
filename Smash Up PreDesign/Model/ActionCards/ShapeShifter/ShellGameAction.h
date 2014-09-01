#pragma once

#include <ActionCard.h>

class ShellGameAction : public ActionCard
{
public:
	ShellGameAction(Player *owner);
	virtual void play(MinionCard *minion);
	virtual void destroy();
private:
	MinionCard *_minion;
};