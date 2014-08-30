#include "MinionCard.h"
#include <ActionCard.h>
#include <Base.h>

MinionCard::MinionCard(Player *owner)
{
	this->initOwner(owner);
	_cardType = BASE_CARD;
}

bool MinionCard::isMinion()
{
	return true;
}

std::vector<ActionCard *> MinionCard::actionsOnMinion()
{
	return _actions;
}

int MinionCard::printedPower()
{
	return _printedPower;
}

int MinionCard::currentPower()
{
	return _printedPower; //TODO modifications here?
}

bool MinionCard::isAffectable()
{
	return true;
}

bool MinionCard::hasTalent()
{
	return _talent;
}

void MinionCard::removeAllActions()
{
	std::vector<ActionCard *>::iterator itActions;
	for (itActions = _actions.begin(); itActions != _actions.end(); itActions++)
	{
		(*itActions)->destory();
	}
}


void MinionCard::destory()
{
	_base->destroyMinion(this);
}

void MinionCard::play(Base *base)
{
	base->playMinion(this);
	_base = base;
}

void MinionCard::play()
{
	//ASSERT
}

void MinionCard::play(MinionCard *minion)
{
	//ASSERT
}


void MinionCard::move(Base *newBase, Base *oldBase)
{
	auto itMinions = std::find(_base->minionsOnBase().begin(), _base->minionsOnBase().end(), this);
	if (itMinions == _base->minionsOnBase().end())
		return;
		// ASSERT
	_base->minionsOnBase().erase(itMinions);
	newBase->moveMinion(this);
	_base = newBase;
}

void MinionCard::discard()
{
	//TODO not sure
}

void MinionCard::useTalent(Player *owner)
{
	// any Minion with a talent should override this method
	assert(false);
}
