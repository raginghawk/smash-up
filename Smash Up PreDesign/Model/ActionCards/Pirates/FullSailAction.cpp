#include "FullSailAction.h"
#include <Board.h>
#include <Player.h>
#include <MinionCard.h>
#include <Event.h>

FullSailAction::FullSailAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Full Sail";
	_cardType = INSTANT_CARD;
}

void FullSailAction::play()
{
	std::vector<MinionCard *> minionOptions = vBoard->playersMinionsInPlay(_currentOwner);
	minionOptions.push_back(NULL); // The back out option because of "any"

	MinionCard *selection;
	Base *newBase;
	while (true)
	{
		selection = _currentOwner->selectCard(minionOptions);
		if (selection)
		{
			newBase = _currentOwner->selectBase(vBoard->otherBases(selection->base()));
			selection->move(newBase);
		}
		else
			break;
	}
}

void FullSailAction::drawn()
{
	vBoard->baseWillScore()->registerListener(this);
}

void FullSailAction::discard()
{
	vBoard->baseWillScore()->unregisterListener(this);
}

//EventListner
void FullSailAction::call(EventData *eventData)
{
	assert(eventData->eventType() == BASE_WILL_SCORE);

	bool playSpecial = true; // TODO: player selection

	if (playSpecial)
		play();
}