#pragma once

#include <Card.h>
#include <UpdateVisibilityFlags.h>

class ActionCard : public Card
{
public:
	ActionCard(Player *owner);
#pragma region Members	
	virtual bool isMinion();
#pragma endregion
	virtual void destroy();
	virtual void play(Base *base);
	virtual void play();
	virtual void play(MinionCard *minion);
	virtual void move(Base *newBase, Base *oldBase);
	virtual void discard();
	virtual bool fUpdate(UpdateVisibilityFlags *flags);
	virtual void update(Base *base);
	virtual void update(MinionCard *minionCard);
};