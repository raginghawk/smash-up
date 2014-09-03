#include "Player.h"
#include <DeckConstructor.h>
#include <MinionCard.h>
#include <Base.h>
#include <Event.h>
#include <Board.h>
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

		_deck = constructor->addDeck(deck, _deck, this);
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
	for (int i = 0; i < count; i++)
	{
		if (optional)
		{
			return false;
		}

		Card * selection = selectCard(_hand);
		selection->discard();
	}
	return true;
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

std::vector<Card *> Player::getPlayableCardsFromDiscards()
{
	std::vector<Card *> empty;
	return empty; /* TODO this mess*/
}

void Player::addVictoryPoint(int victoryPoints)
{
	_victoryPoints += victoryPoints;
}

int Player::currentVictoryPoints()
{
	return _victoryPoints;
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

void Player::playCard(Card * cardToPlay)
{
	switch (cardToPlay->cardType())
	{
	case BASE_CARD:
		cardToPlay->play(selectBase());
		break;
	case INSTANT_CARD:
		cardToPlay->play();
		break;
	case MINION_CARD: // MinionCard should probably be renamed ... it is a card played on a minion :/ ugh
		assert(!cardToPlay->isMinion());
		cardToPlay->play(selectCard(vBoard->minionsInPlay()), (ActionCard *)cardToPlay);
		break;
	default:
		assert(false);
	}
}


void Player::takeTurn()
{
	// These are set before begining of turn fires to prevent it from paving over additional minions/actions fireEvent could give. For now they are explicitly cleared and set to prevent carry over problems.
	_actionsRemaining = 1;
	_minionsRemaining.clear();
	_minionsRemaining.push_back(new MinionPlayableStruct(INT_MAX, NULL));

	_beginingOfTurn->fireEvent();

	while (true)
	{
		if (_actionsRemaining == 0 && _minionsRemaining.size() == 0) /* TODO: Look at if this assumption is true :/ it may not be. Also Minion Playable Struct may need to include reference the minion for those damn Zombies (Ten Z)*/
			break;

		std::vector<Card *>::iterator itCards;
		std::vector<Card *> playableCards = getPlayableCardsFromDiscards();

		for (itCards = _hand.begin(); itCards != _hand.end(); itCards++)
		{
			if ((*itCards)->fPlay(this))
			{
				playableCards.push_back(*itCards);
			}
		}

		if (playableCards.size() == 0) /* TODO same as above. Check if assumption is valid... damn tenacious z's, also need someway to add Spectre and Zombies to playableCards*/
			break;

		 playCard(selectCard(playableCards));
	}
}

void Player::endTurn()
{
	_endOfTurn->fireEvent();
	drawCard(2);
	
	if (_hand.size() > 10)
	{
		discardCard((_hand.size() - 10), false);
	}
}

MinionCard * Player::selectCard(std::vector<MinionCard *>options)
{
	//TODO select card
	return NULL;
}

ActionCard * Player::selectCard(std::vector<ActionCard *>options)
{
	//TODO select card
	return NULL;
}

Card * Player::selectCard(std::vector<Card *>options)
{
	//TODO select card
	return NULL;
}

Base * Player::selectBase()
{
	//TODO select base
	return NULL;
}
