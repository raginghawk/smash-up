#pragma once

#include <vector>
#include <GameGlobals.h>
#include <MinionPlayableStruct.h>

class Deck;
class Card;
class MinionCard;
class ActionCard;
class Base;
class Event;

class Player
{
public:

	Player(deckType firstDeck, deckType secondDeck);
	~Player();
#pragma region Members
	int playerNumber();
	int handSize();

	MinionCard *minionInDiscard(int maxPower);
	MinionCard *minionInDeck(int maxPower);
	std::vector<MinionCard *> minionsInHand();

	void addVictoryPoint(int victoryPoints);
	int currentVictoryPoints();

	Event *beginingOfTurn();
	Event *endOfTurn();

	void modifyMinionPower(int modification);
	int minionPowerModification();

	int actionsRemaining();
	std::vector<MinionPlayableStruct *> minionsRemaining();
#pragma endregion
	MinionCard *selectCard(std::vector<MinionCard *>options);
	ActionCard *selectCard(std::vector<ActionCard *>options);
	Card *selectCard(std::vector<Card *>options);

	Base *selectBase();

	bool discardCard(int count, bool optional);
	void addMinionToPlayableDiscards(MinionCard *minion);
	bool removeFromDiscard(Card *);
	void drawCard(int count);
	void addCardToHand(Card *card);
	void shuffleDeck(bool withDiscards);
	void shuffleMinionInDeck(MinionCard *minion);
	void addActionCount(int count);
	void addMinionCount(int maxPower, Base *onBase);

	void takeTurn();
	void endTurn();
private:
	std::vector<Card *> _deck;
	std::vector<Card *> _hand;
	std::vector<Card *> _discards;
	std::vector<MinionCard *> _playableDiscards;
	std::vector<MinionPlayableStruct *> _minionsRemaining;
	Event *_endOfTurn;
	Event *_beginingOfTurn;
	int _minionPowerModification;
	int _actionsRemaining;
	int _victoryPoints;
	int _playerNumber;
	void initClassVariables();
};