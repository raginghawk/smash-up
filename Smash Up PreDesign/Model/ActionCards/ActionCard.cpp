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

void ActionCard::destroy()
{

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
		Base *base;
		bases = vBoard->bases();
		//TODO Select Base
		base = NULL;
		base->actionsOnBase().push_back(this);
		break;
	}
}

void ActionCard::play(MinionCard *minion, ActionCard *action)
{
	//TODO probably call update on minion or we could leave it to the minionCard to update its visibilty. My guess is power is updated all the time :/
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
