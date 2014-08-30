#include<vector>

class Base;
class Player;
class Events;
class MinionCard;

class Board // Board is a singleton TODO: Add singleton check to initiator
{
public:
	Board(std::vector<Player *> players);

#pragma region Members
	std::vector<Base *> bases();
	Player *currentPlayer();
#pragma endregion

	std::vector<MinionCard *> minionsOnBases(Base * base);
	std::vector<MinionCard *> minionsInPlay();
	void startGame();

private:
	std::vector<Events *> _endOfTurnEvents;
	std::vector<Events *> _beginingOfTurnEvents;
	std::vector<Base *> _bases;
	std::vector<Base *> _baseDiscards;
	std::vector<Base *> _baseDeck;
	std::vector<Player *> _players;
	Player *_currentPlayer;
};