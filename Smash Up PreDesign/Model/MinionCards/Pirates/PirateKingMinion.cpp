#include "PirateKingMinion.h"
#include <Base.h>
#include <Player.h>
#include <Board.h>
#include <Event.h>

PirateKingMinion::PirateKingMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 5;
	_name = "Pirate King";
}

void PirateKingMinion::play(Base *base, MinionCard *card)
{
	MinionCard::play(base, card);
	vBoard->baseWillScore()->registerListener(this);
}

void PirateKingMinion::discard()
{
	vBoard->baseWillScore()->unregisterListener(this);
}

void PirateKingMinion::call(EventData *eventData)
{
	assert(eventData->eventType() == BASE_WILL_SCORE);

	if (eventData->base() == _base)
		return;

	std::vector<Base *> options;
	options.push_back(eventData->base());
	options.push_back(NULL);

	Base *selectedBase = _currentOwner->selectBase(options);
	if (selectedBase)
		move(selectedBase);
}