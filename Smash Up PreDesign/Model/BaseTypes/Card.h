#pragma once
#include <vector>
#include <string>

#include <GameGlobals.h>

class Player;
class MinionCard;
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
	CardType cardType();

	void setCurrentOwner(Player *owner);

#pragma endregion

	void initOwner(Player *owner);

	virtual void destory() = 0;
	virtual void play(Base *base) = 0;
	virtual void play() = 0;
	virtual void play(MinionCard *minion) = 0;
	virtual void move(Base *newBase, Base *oldBase) = 0;
	virtual void discard() = 0;

protected:
	Player *_owner;
	Player *_currentOwner;
	std::string _name;
	Base *_base;
	CardType _cardType;
};