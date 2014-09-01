#pragma once

#include <ActionCard.h>

class MakeContact : public ActionCard
{
public:
	MakeContact::MakeContact(Player *owner);
	virtual void play(MinionCard *minionCard, ActionCard *action);
	virtual bool fUpdate(UpdateVisibilityFlags *flags);
	virtual void update(MinionCard *minionCard);
	virtual bool fPlay(Player *player);
	virtual void destroy();
	virtual ActionCard *copy();
private:
	MinionCard *_selection;
};