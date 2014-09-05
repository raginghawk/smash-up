#include "Transmogrify.h"
#include <Board.h>
#include <Player.h>
#include <MinionCard.h>

Transmogrify::Transmogrify(Player *owner) : ActionCard(owner)
{
	this->_name = "Transmogrify";
	_cardType = INSTANT_CARD;
}

void Transmogrify::play()
{
	MinionCard *selection = _currentOwner->selectCard(vBoard->playersMinionsInPlay(_currentOwner));
	int selectionPower = selection->currentPower(selection);
	selection->destroy();
	
	MinionCard *minionToPlay = _currentOwner->minionInDeck(selectionPower);
	Base *base = _currentOwner->selectBase(_currentOwner->baseOptions(minionToPlay));
	minionToPlay->play(base);

	_currentOwner->shuffleDeck(false);
}