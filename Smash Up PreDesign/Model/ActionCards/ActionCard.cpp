#include "ActionCard.h"
#include <Board.h>
#include <Base.h>
#include <MinionCard.h>

ActionCard::ActionCard(Player *owner)
{
	this->initOwner(owner);
}

bool ActionCard::isMinion()
{
	return false;
}

void ActionCard::destroy()
{

}

void ActionCard::play(Base *base)
{

}

void ActionCard::play()
{
	std::vector<MinionCard *> minionsInPlay;
	std::vector<Base *> bases;

	switch (_cardType)
	{
	case MINION_CARD:
		MinionCard *minionCard;
		minionsInPlay = vBoard->minionsInPlay();
		//TODO Select Minion
		minionCard = NULL;
		minionCard->actionsOnMinion().push_back(this);
		//TODO probably call update on minion or we could leave it to the minionCard to update its visibilty. My guess is power is updated all the time :/
		break;
	case BASE_CARD:
		Base *base;
		bases = vBoard->bases();
		//TODO Select Base
		base = NULL;
		base->actionsOnBase().push_back(this);
		break;
	}
}

void ActionCard::play(MinionCard *minion)
{

}


void ActionCard::move(Base *newBase, Base *oldBase)
{
	assert(_cardType == BASE_CARD);
}

void ActionCard::discard()
{

}

bool ActionCard::fUpdate(UpdateVisibilityFlags *flags)
{
	assert(_cardType != INSTANT_CARD);
	return false;
}

void ActionCard::update(Base *base)
{

}

void ActionCard::update(MinionCard *minionCard)
{

}
