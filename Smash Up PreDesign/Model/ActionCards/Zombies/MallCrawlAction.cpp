#include "MallCrawlAction.h"
#include <Player.h>

MallCrawlAction::MallCrawlAction(Player *owner) : ActionCard(owner)
{
	_name = "Mall Crawl";
	_cardType = INSTANT_CARD;
}

void MallCrawlAction::play()
{
	ActionCard::play();

	Card *selection = _currentOwner->selectCard(_currentOwner->deck());

	while (true)
	{
		//TODO add bail out possibly multi select :)
		Card *toAdd = _currentOwner->removeFromDeck(selection->name());
		if (toAdd)
		{
			_currentOwner->addCardToDiscardPile(toAdd);
		}
		else
			break;
	}

	_currentOwner->shuffleDeck(false);
}