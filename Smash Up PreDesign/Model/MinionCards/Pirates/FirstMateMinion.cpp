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
	//TODO: Fix bugged interaction with copy cat :/
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

	std::vector<Base *> baseOptions = vBoard->otherBases(_base);
	baseOptions.push_back(NULL); // This is the I choose to discard option

	Base *selectedBase = _currentOwner->selectBase(baseOptions);
	if (selectedBase)
		move(selectedBase);
	else
		MinionCard::discard();
}