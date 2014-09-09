#include "BactaTheFuture.h"
#include <Player.h>
#include <Board.h>
#include <MinionCard.h>

BactaTheFuture::BactaTheFuture(Player *owner) : ActionCard(owner)
{
	this->_name = "Bacta the Future";
	_cardType = INSTANT_CARD;
}

void BactaTheFuture::play()
{
	MinionCard *selection = _currentOwner->selectCard(vBoard->minionsInPlay());
	selection->destroy();

	Player * cardOwner = selection->currentOwner();
	cardOwner->addMinionCount(INT_MAX, NULL);

	if (cardOwner != _currentOwner)
		cardOwner->playMinionOutOfTurn();
}

bool BactaTheFuture::fPlay(Player *player)
{
	if (vBoard->minionsInPlay().size() == 0)
		return false;
}
