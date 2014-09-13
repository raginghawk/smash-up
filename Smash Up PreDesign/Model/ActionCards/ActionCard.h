#pragma once

#include <Card.h>

class ActionCard : public Card
{
public:
	ActionCard(Player *owner);
#pragma region Members	
	virtual bool isMinion();
#pragma endregion
	virtual bool destroy();
	virtual bool fPlay(Player *player);
	virtual void play(Base *base);
	virtual void play();
	virtual void play(MinionCard *minion, ActionCard *action);
	virtual void move(Base *newBase);
	virtual void discard();
	virtual bool fUpdate(UpdateVisibilityFlags *flags);
	virtual void update(Base *base);
	virtual void update(MinionCard *minionCard);

	virtual ActionCard *copy();
};