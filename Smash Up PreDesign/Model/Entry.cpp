#include <GameGlobals.h>
#include <Player.h>
#include <Board.h>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(void)
{
	std::vector<Player *> players;
	players.push_back(new Player(GHOST, GHOST));
	players.push_back(new Player(SHAPE_SHIFTER, SHAPE_SHIFTER));

	vBoard = new Board(players);

	// get new random number for shuffle
	vBoard->startGame();

	//bool ending = false;

	//do
	//{
	//	unsigned int iSelection;

	//	printf("Current hand has: \n");
	//	players.at(0)->spew_hand();
	//	printf("\nCurrent bases are: \n");
	//	vBoard->spew_bases();
	//	printf("Pick a card (1-size) or 0 to exit:");
	//	scanf_s("%u", &iSelection);
	//	if (iSelection == 0)
	//	{
	//		ending = true;
	//	}
	//	else
	//	{
	//		Card *card = players.at(0)->getCard(iSelection - 1);

	//		if (card->isMininion())
	//		{
	//			players.at(0)->playMinionOnBase(card, 1);
	//		}
	//		else
	//		{
	//			players.at(0)->playAction(dynamic_cast<ActionCard*>(card));
	//		}
	//	}
	//} while (!ending);
}