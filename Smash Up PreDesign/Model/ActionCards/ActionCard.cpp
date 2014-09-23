#include "ActionCard.h"
#include <Board.h>
#include <Base.h>
#include <MinionCard.h>
#include <Player.h>

ActionCard::ActionCard(Player *owner)
{
	this->initOwner(owner);
}

bool ActionCard::isMinion()
{
	return false;
}

bool ActionCard::destroy()
{
	return true;
	//TODO
}

bool ActionCard::fPlay(Player *player)
{
	if (player->actionsRemaining() == 0)
		return false;

	if (_cardType == MINION_CARD && vBoard->minionsInPlay().size() == 0)
		return false;

	if (_cardType == BASE_CARD && vBoard->bases().size() == 0)
		return false;

	return true;
}


void ActionCard::play(Base *base)
{
	base->actionsOnBase().push_back(this);
	this->setBase(base);
}

void ActionCard::play()
{
	std::vector<MinionCard *> minionsInPlay;
	std::vector<Base *> bases;
	MinionCard *minionCard;

	switch (_cardType)
	{
	case MINION_CARD:
		minionCard = _currentOwner->selectCard(vBoard->minionsInPlay());
		minionCard->actionsOnMinion().push_back(this);
		play(minionCard,this);
		break;
	case BASE_CARD:
		Base *selection = _currentOwner->selectBase(bases = vBoard->bases());
		this->play(selection);
		break;
	}
}

void ActionCard::play(MinionCard *minion, ActionCard *action)
{
	if (action != this)
	{
		return; /* The cellular bonding case. Cellular Bonding will attach itself to the minion and forward all calls to the copied class*/
	}
	minion->actionsOnMinion().push_back(action);
}


void ActionCard::move(Base *newBase)
{
	assert(_cardType == BASE_CARD);
	if (_cardType != BASE_CARD)
		return;

	this->base()->removeCard(this);
	newBase->moveCard(this);
}

void ActionCard::discard()
{
//TODO
}

int ActionCard::powerModification(Player *player)
{
	return 0;
}

ActionCard * ActionCard::copy()
{
	assert(true); /*Subclasses that can be copied should override this (aka cards of type Minion_Card*/
	return NULL;
}