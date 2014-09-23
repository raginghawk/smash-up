#pragma once

#include <ActionCard.h>

class MakeContact : public ActionCard
{
public:
	MakeContact::MakeContact(Player *owner);
	virtual void play(MinionCard *minionCard, ActionCard *action);
	virtual bool fPlay(Player *player);
	virtual bool destroy();
	virtual ActionCard *copy();
private:
	MinionCard *_selection;
};