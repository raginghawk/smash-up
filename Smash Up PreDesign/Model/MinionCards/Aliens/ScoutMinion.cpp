#include "ScoutMinion.h"
#include <Base.h>
#include <Player.h>
#include <Board.h>
#include <Event.h>

ScoutMinion::ScoutMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "First Mate";
	_faction = PIRATE;
}

void ScoutMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	_base->baseDidScore()->registerListener(this);
}

void ScoutMinion::discard()
{
	_base->baseDidScore()->unregisterListener(this);
}

void ScoutMinion::move(Base *newBase)
{
	_base->baseDidScore()->unregisterListener(this);
	newBase->baseDidScore()->registerListener(this);
	MinionCard::move(newBase);
}

void ScoutMinion::call(EventData *eventData)
{
	assert(eventData->eventType() == BASE_DID_SCORE);
	assert(eventData->base() == _base);

	//TODO BOOL CHOICE to hand or discard
	bool discard = false;
	if (!discard)
	{
		this->returnToOwnersHand();
	}
}