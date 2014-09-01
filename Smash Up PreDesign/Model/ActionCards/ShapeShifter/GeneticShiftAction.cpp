#include "GeneticShiftAction.h"
#include <Player.h>
#include <Event.h>
#include <Board.h>
#include <MinionCard.h>

GeneticShift::GeneticShift(Player *owner) : ActionCard(owner)
{
	this->_name = "Genetic Shift";
	_cardType = INSTANT_CARD;
	_selection = NULL;
}

void GeneticShift::play()
{
	//TODO selection +1 for everyone or +3 to one
	bool focusPower = false;
	_currentOwner->endOfTurn()->registerListener(this);

	if (focusPower)
	{
		_selection = _currentOwner->selectCard(vBoard->playersMinionsInPlay(_currentOwner));
		_selection->modifyCurrentPower(3);
	} else 
	{
		_currentOwner->modifyMinionPower(1);
	}
}

void GeneticShift::call()
{
	if (_selection)
	{
		_selection->modifyCurrentPower(-3);
	}
	else
	{
		_currentOwner->modifyMinionPower(-1);
	}
}