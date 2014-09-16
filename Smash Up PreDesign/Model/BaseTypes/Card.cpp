#include "Card.h"
#include <Player.h>

void Card::initOwner(Player *owner)
{
	_owner = owner;
	_currentOwner = owner;
}

Player * Card::owner()
{
	return _owner;
}

Faction Card::faction()
{
	return _faction;
}


Player * Card::currentOwner()
{
	return _currentOwner;
}

void Card::setCurrentOwner(Player *owner)
{
	_currentOwner = owner;
}

std::string Card::name()
{
	return _name;
}

Base * Card::base()
{
	return _base;
}

void Card::setBase(Base *base)
{
	_base = base;
}

CardType Card::cardType()
{
	return _cardType;
}

void Card::drawn()
{
	// in most cases being drawn doesn't require anything so just have fun. Some subclasses break that rule
}

void Card::discardFromHand()
{
	//TODO remove it from hand and add it to its owner's discard pile
}
