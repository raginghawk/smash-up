#include "ReallyAction.h"
#include <Player.h>
#include <Board.h>
#include <MinionCard.h>

ReallyAction::ReallyAction(Player *owner) : ActionCard(owner)
{
	this->_name = "... Really?!";
	_cardType = INSTANT_CARD;
}

void ReallyAction::play()
{
	MinionCard *selection = _currentOwner->selectCard(vBoard->playersMinionsInPlay(_currentOwner));
	int maxPower = selection->currentPower(selection);

	selection->destroy();

	MinionCard *toPlay = _currentOwner->minionInDiscard(maxPower, false);
	if (toPlay)
		toPlay->play(_currentOwner->selectBase(_currentOwner->baseOptions(toPlay)));
}