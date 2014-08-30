#include "SeanceAction.h"
#include <Player.h>

SeanceAction::SeanceAction(Player *owner) : ActionCard(owner)
{
	_name = "Seance";
	_cardType = INSTANT_CARD;
}

void SeanceAction::play()
{
	ActionCard::play();
	if (_currentOwner->handSize() < 3)
	{
		int cardsToDraw = 5 - _currentOwner->handSize();
		_currentOwner->drawCard(cardsToDraw);
	}
}