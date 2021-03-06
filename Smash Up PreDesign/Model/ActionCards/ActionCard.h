#pragma once
//TODO add factions to everybody :/
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
	
	virtual int powerModification(Player *player);


	virtual ActionCard *copy();
};