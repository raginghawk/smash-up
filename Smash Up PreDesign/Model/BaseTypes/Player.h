#pragma once

#include <vector>
#include <GameGlobals.h>

class Deck;
class Card;
class MinionCard;
class Base;

class Player
{
public:

	Player(deckType firstDeck, deckType secondDeck);
#pragma region Members
	int playerNumber();
	MinionCard *minionInDiscard(int maxPower);
	MinionCard *minionInDeck(int maxPower);
	int handSize();

#pragma endregion
	bool discardCard(int count, bool optional);
	void addMinionToPlayableDiscards(MinionCard *minion);
	void addVictoryPoint(int victoryPoints);
	bool removeFromDiscard(Card *);
	void drawCard(int count);
	void addCardToHand(Card *card);
	void shuffleDeck(bool withDiscards);
	void shuffleMinionInDeck(MinionCard *minion);
	void addActionCount(int count);
	void addMinionCount(int maxPower, Base *onBase);
	void takeTurn();

private:
	std::vector<Card *> _deck;
	std::vector<Card *> _hand;
	std::vector<Card *> _discards;
	std::vector<MinionCard *> _playableDiscards;
	int _actionsRemaining;
	int _victoryPoints;
	int _playerNumber;
	void initClassVariables();
};