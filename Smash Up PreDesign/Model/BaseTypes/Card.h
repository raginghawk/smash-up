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
	Faction faction();
	std::string name();
	Base *base();
	void setBase(Base *base);
	CardType cardType();
	void setCurrentOwner(Player *owner);

#pragma endregion

	void initOwner(Player *owner);

	virtual bool destroy() = 0;
	virtual bool fPlay(Player *player) = 0;
	virtual void drawn();

	virtual void move(Base *newBase) = 0;
	virtual void discard() = 0;
	virtual void discardFromHand();

protected:
	Player *_owner;
	Player *_currentOwner;
	std::string _name;
	Base *_base;
	CardType _cardType;
	Faction _faction;
};