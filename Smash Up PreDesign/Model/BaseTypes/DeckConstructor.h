#include <vector>
#include <GameGlobals.h>

class Player;
class Card;

class DeckConstructor
{
public:
	std::vector<Card *> addDeck(deckType deckToAdd, std::vector<Card *>deck, Player *owner);
private:
	std::vector<Card *> addGhosts(Player *owner);
	std::vector<Card *> addShapeShifters(Player *owner);;
};