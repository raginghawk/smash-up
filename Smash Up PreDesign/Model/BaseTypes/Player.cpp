#include "Player.h"
#include <DeckConstructor.h>
#include <MinionCard.h>
#include <Base.h>
#include <Event.h>
#include <algorithm>

Player::Player(deckType firstDeck, deckType secondDeck)
{
	DeckConstructor *constructor = new DeckConstructor();

	initClassVariables();

	for (int i = 0; i < 2; i++)
	{
		deckType deck = firstDeck;
		if (i == 1)
			deck = secondDeck;
		switch (deck)
		{
		case GHOST_DECK:
			_deck = constructor->addDeck(deck, _deck, this);
			break;
		}
	}

	delete(constructor);
}

Player::~Player()
{
	delete(_endOfTurn);
	delete(_beginingOfTurn);
}

void Player::initClassVariables()
{
	_victoryPoints = 0;
	_endOfTurn = new Event(END_OF_TURN);
	_beginingOfTurn = new Event(BEGINING_OF_TURN);
	_minionPowerModification = 0;
}

bool Player::discardCard(int count, bool optional)
{
	return true;
	//select a card
}

int Player::handSize()
{
	return _hand.size();
}

int Player::playerNumber()
{
	return _playerNumber;
}

Event *Player::endOfTurn()
{
	return _endOfTurn;
}

void Player::modifyMinionPower(int modification)
{
	_minionPowerModification += modification;
}

int Player::minionPowerModification()
{
	return _minionPowerModification;
}

Event *Player::beginingOfTurn()
{
	return _beginingOfTurn;
}

void Player::addMinionToPlayableDiscards(MinionCard *minion)
{
	_playableDiscards.push_back(minion);
}

void Player::addVictoryPoint(int victoryPoints)
{
	_victoryPoints += victoryPoints;
}

std::vector<MinionCard *> Player::minionsInHand()
{
	std::vector<Card *>::iterator itCards;
	std::vector<MinionCard *>minionsInHand;

	for (itCards = _hand.begin(); itCards != _hand.end(); itCards++)
	{
		if ((*itCards)->isMinion())
		{
			minionsInHand.push_back((MinionCard *)*itCards);
		}
	}
	return minionsInHand;
}


MinionCard *Player::minionInDiscard(int maxPower)
{
	std::vector<MinionCard *>minionsInDiscard;
	std::vector<Card *>::iterator itCards;
	
	for (itCards = _discards.begin(); itCards != _discards.end(); itCards++)
	{
		if ((*itCards)->isMinion() && ((MinionCard *)*itCards)->printedPower() <= maxPower)
		{
			minionsInDiscard.push_back((MinionCard *)*itCards);
		}
	}

	//TODO: select on of the minions in minionsInDiscard
	return NULL;
}

MinionCard *Player::minionInDeck(int maxPower)
{
	std::vector<MinionCard *>minionsInDeck;
	std::vector<Card *>::iterator itCards;

	for (itCards = _deck.begin(); itCards != _deck.end(); itCards++)
	{
		if ((*itCards)->isMinion() && ((MinionCard *)*itCards)->printedPower() <= maxPower)
		{
			minionsInDeck.push_back((MinionCard *)*itCards);
		}
	}

	//TODO: select on of the minions in minionsInDeck
	return NULL;
}

bool Player::removeFromDiscard(Card *card)
{
	std::vector<Card *>::iterator itCards;

	for (itCards = _discards.begin(); itCards != _discards.end(); itCards++)
	{
		// If the card is equal or if they have the same name (name shouldn't matter and is needed for Across the Divide
		if (card == *itCards || !(strcmp(card->name().c_str(), (*itCards)->name().c_str())))
		{
			_discards.erase(itCards);
			return true;
		}
	}
	return false;
}

void Player::drawCard(int cCards)
{
	for (int i = 0; i < cCards; i++)
	{
		if (_deck.size() == 0)
			shuffleDeck(true);
		
		_hand.push_back(_deck.back());
		_deck.pop_back();
	}
}

void Player::addCardToHand(Card *card)
{
	_hand.push_back(card);
}


void Player::shuffleDeck(bool withDiscards)
{
	if (withDiscards)
	{
		_playableDiscards.clear();

		while (_discards.size() != 0)
		{
			_deck.push_back(_discards.back());
			_discards.pop_back();
		}
	}

	std::random_shuffle(_deck.begin(), _deck.end());
}

void Player::shuffleMinionInDeck(MinionCard *minion)
{
	if (minion->base())
	{
		minion->base()->removeMinion(minion);
	}

	this->shuffleDeck(false);
}

void Player::addActionCount(int count)
{
	_actionsRemaining += count;
}

void Player::addMinionCount(int maxPower, Base *onBase)
{
	_minionsRemaining.push_back(new MinionPlayableStruct(maxPower, onBase));
}

int Player::actionsRemaining()
{
	return _actionsRemaining;
}

std::vector<MinionPlayableStruct *> Player::minionsRemaining()
{
	return _minionsRemaining;
}

void Player::takeTurn()
{
	_actionsRemaining = 1;
	_minionsRemaining.clear();
	_minionsRemaining.push_back(new MinionPlayableStruct(INT_MAX, NULL));

	//TODO selectCard possiblly move this to private turn loop ?
	int cardIndexToPlay = 0;
	while (true)
	{
		Card *cardToPlay = _hand.at(cardIndexToPlay);
		switch (cardToPlay->cardType())
		{
		case BASE_CARD:
			//TODO select base
			Base *base;
			base = NULL;
			cardToPlay->play(base);
			break;
		case INSTANT_CARD:
		case MINION_CARD:
			cardToPlay->play();
			break;
		default:
			assert(false);
		}
	}
}

MinionCard * Player::selectCard(std::vector<MinionCard *>options)
{
	//TODO select card
	return NULL;
}

Base * Player::selectBase()
{
	//TODO select base
	return NULL;
}
