#pragma once
#include <vector>
#include <string>

#include <GameGlobals.h>
#include <UpdateVisibilityFlags.h>

class Player;
class MinionCard;
class ActionCard;
class Base;

enum CardType
{
	NIL_CARD,
	BASE_CARD,
	MINION_CARD,
	INSTANT_CARD
};

class Card
{
public:
#pragma region members
	virtual bool isMinion() = 0;
	Player *owner();
	Player *currentOwner();
	std::string name();
	Base *base();
	void setBase(Base *base);
	CardType cardType();
	void setCurrentOwner(Player *owner);

#pragma endregion

	void initOwner(Player *owner);

	virtual void destroy() = 0;
	virtual bool fPlay(Player *player) = 0;
	virtual void play(Base *base) = 0;
	virtual void play() = 0;
	virtual void play(MinionCard *minion, ActionCard *action) = 0;
	virtual bool fUpdate(UpdateVisibilityFlags *flags) = 0;
	virtual void update(Base *base) = 0;

	virtual void move(Base *newBase) = 0;
	virtual void discard() = 0;

protected:
	Player *_owner;
	Player *_currentOwner;
	std::string _name;
	Base *_base;
	CardType _cardType;
};