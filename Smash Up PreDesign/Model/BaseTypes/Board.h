#pragma once
#include<vector>

class Base;
class Player;
class Event;
class MinionCard;
class ActionCard;

class Board // Board is a singleton TODO: Add singleton check to initiator
{
public:
	Board(std::vector<Player *> players);
	~Board();
#pragma region Members
	std::vector<Base *> bases();
	std::vector<Base *> otherBases(Base *base);
	std::vector<Base *> basesWithMinionFromPlayer(Player *player);
	std::vector<Player *> players();
	Player *currentPlayer();
	
	Event *baseWillScore();
#pragma endregion

	std::vector<MinionCard *> minionsOnBase(Base * base);
	std::vector<MinionCard *> minionsInPlay();
	std::vector<MinionCard *> otherPlayersMinionsInPlay(Player *player);
	std::vector<MinionCard *> playersMinionsInPlay(Player *player);
	std::vector<ActionCard *> actionsOnMinions();
	void startGame();

private:
	std::vector<Event *> _endOfTurnEvents;
	std::vector<Event *> _beginingOfTurnEvents;
	std::vector<Base *> _bases;
	std::vector<Base *> _baseDiscards;
	std::vector<Base *> _baseDeck;
	std::vector<Player *> _players;

	Player *_currentPlayer;
	Event *_baseWillScore;

	Player *pWinnerIfGameOver();
	void evaulateBases();
	void initBases();
	void drawBase();
};