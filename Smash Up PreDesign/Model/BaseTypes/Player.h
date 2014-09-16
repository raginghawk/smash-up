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
enum Faction;

class Player
{
public:

	Player(Faction firstDeck, Faction secondDeck);
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
	std::vector<MinionPlayableStruct *> &minionsRemaining();
#pragma endregion

	MinionCard *selectCard(std::vector<MinionCard *>options);
	ActionCard *selectCard(std::vector<ActionCard *>options);
	Card *selectCard(std::vector<Card *>options);
	Base *selectBase(std::vector<Base *>options);
	Player *selectPlayer(std::vector<Player *>options);
	Faction selectFaction();
	MinionPlayableStruct * selectMinionStruct(std::vector<MinionPlayableStruct *>options);

	std::vector<Base *> baseOptions(Card *card);
	std::vector<MinionPlayableStruct *> minionStructOptions(Base *base, MinionCard *minion);
	
	void removeMinionStruct(MinionPlayableStruct *playableStruct);
	void Player::removeCardFromHand(Card *card);

	bool discardCard(int count, bool optional);
	bool removeFromDiscard(Card *);
	void drawCard(int count);
	void addCardToHand(Card *card);


	void shuffleDeck(bool withDiscards);
	void shuffleMinionInDeck(MinionCard *minion);

	void addActionCount(int count);
	void addMinionCount(int maxPower, Base *onBase);

	void addMinionToPlayableDiscards(MinionCard *minion);
	std::vector<Card *> getPlayableCardsFromDiscards();

	void playCard(Card *);
	void playLoop();

	void takeTurn();
	void endTurn();
	void playMinionOutOfTurn();

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
	void clearRemainingActionsandMinions();
};