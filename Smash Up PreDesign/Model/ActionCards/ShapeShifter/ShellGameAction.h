#pragma once

#include <ActionCard.h>

class ShellGameAction : public ActionCard
{
public:
	ShellGameAction(Player *owner);
	virtual void play(MinionCard *minion);
	virtual bool destroy();
private:
	MinionCard *_minion;
};