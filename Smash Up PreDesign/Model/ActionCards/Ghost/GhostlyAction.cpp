#include "GhostlyAction.h"
#include <Player.h>

GhostlyAction::GhostlyAction(Player *owner) : ActionCard(owner)
{
	this->_name = "Ghostly Action";
	_cardType = INSTANT_CARD;
}

void GhostlyAction::play()
{
	ActionCard::play();
	_owner->addActionCount(1);
	_owner->addMinionCount(INT_MAX,NULL);

}