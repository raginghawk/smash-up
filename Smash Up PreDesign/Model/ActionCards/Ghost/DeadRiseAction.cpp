#pragma once
#include "DeadRiseAction.h"
#include <Player.h>
#include <MinionCard.h>

DeadRiseAction::DeadRiseAction(Player *owner) : ActionCard(owner)
{
	_name = "The Dead Rises";
	_cardType = INSTANT_CARD;
}

void DeadRiseAction::play()
{
	ActionCard::play();

	while (true)
	{
		MinionCard *selection = _currentOwner->minionInDiscard(INT_MAX);
		if (_currentOwner->discardCard(selection->printedPower() + 1, true))
		{
			Base *base = _currentOwner->selectBase(_currentOwner->baseOptions(selection));
			selection->play(base);
		}
	}
}