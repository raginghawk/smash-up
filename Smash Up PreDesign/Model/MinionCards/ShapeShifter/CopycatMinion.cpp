#include "CopycatMinion.h"
#include <Player.h>
#include <Event.h>
#include <Board.h>

CopycatMinion::CopycatMinion(Player *owner) : MinionCard(owner)
{
	_printedPower = 2;
	_name = "Copycat";
	_selectedMinion = NULL;
}

void CopycatMinion::play(Base *base)
{
	_currentOwner->endOfTurn()->registerListener(this);
	std::vector<MinionCard *> otherPlayersMinions = vBoard->otherPlayersMinionsInPlay(_currentOwner);

	if (otherPlayersMinions.size() == 0)
	{
		MinionCard::play(base, this);
		return;
	}

	_selectedMinion = NULL;
	if (_selectedMinion->hasTalent())
	{
		_talent = true;
	}
	_selectedMinion->play(base, this);
}

void CopycatMinion::destroy(MinionCard *card)
{
	_selectedMinion->destroy(this);
	card->currentOwner()->endOfTurn()->unregisterListener((CopycatMinion *)card);
}


void CopycatMinion::useTalent(Player *owner, MinionCard *card)
{
	if (_talent)
		_selectedMinion->useTalent(owner, this);
}

void CopycatMinion::call(EventData *eventData)
{
	assert(eventData->eventType() == END_OF_TURN);

	_talent = false;
	_selectedMinion = NULL;
	_currentOwner->endOfTurn()->unregisterListener(this);
}