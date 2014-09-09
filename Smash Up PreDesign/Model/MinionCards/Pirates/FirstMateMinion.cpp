#include "FirstMateMinion.h"
#include <Base.h>
#include <Player.h>
#include <Board.h>
#include <Event.h>

FirstMateMinion::FirstMateMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "First Mate";
}

void FirstMateMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	_base->baseDidScore()->registerListener(this);
}

void FirstMateMinion::discard()
{
	_base->baseDidScore()->unregisterListener(this);
}

void FirstMateMinion::move(Base *newBase)
{
	_base->baseDidScore()->unregisterListener(this);
	newBase->baseDidScore()->registerListener(this);
	MinionCard::move(newBase);
}

void FirstMateMinion::call(EventData *eventData)
{
	assert(eventData->eventType() == BASE_DID_SCORE);
	assert(eventData->base() == _base);

	Base *selectedBase = _currentOwner->selectBase(vBoard->bases());
	if (_base != selectedBase)
	{
		move(selectedBase);
	}
}