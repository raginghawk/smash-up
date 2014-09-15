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