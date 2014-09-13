#include "DeckConstructor.h"
#include <Minions.h>
#include <Actions.h>
#include <algorithm>	/* random_shuffle*/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


std::vector<Card *> DeckConstructor::addDeck(deckType deckToAdd, std::vector<Card *>deck, Player *owner)
{
	std::vector<Card *> newDeck;

	switch (deckToAdd)
	{
	case GHOST_DECK:
		newDeck = addGhosts(owner);
		break;
	case SHAPESHIFTER_DECK:
		newDeck = addShapeShifters(owner);
		break;
	case PIRATE_DECK:
		newDeck = addPirates(owner);
		break;
	default:
		assert(true); /*Should never have a deckType that isn't covered*/
	}

	if (deck.size() == 0)
	{
		return newDeck;
	}
	else
	{
		newDeck.reserve(deck.size() + newDeck.size());
		newDeck.insert(newDeck.end(), deck.begin(), deck.end());

		std::srand(unsigned(time(0)));
		std::random_shuffle(newDeck.begin(), newDeck.end());
		return newDeck;
	}
}

std::vector<Card *> DeckConstructor::addGhosts(Player *owner)
{
	std::vector<Card *> ghostDeck;

	//Minions
	for (int i = 0; i < 4; i++)
	{
		ghostDeck.push_back(new GhostMinion(owner));
	}
	for (int i = 0; i < 3; i++)
	{
		ghostDeck.push_back(new SpiritMinion(owner));
	}
	for (int i = 0; i < 2; i++)
	{
		ghostDeck.push_back(new HauntingMinion(owner));
	}
	ghostDeck.push_back(new SpectreMinion(owner));

	//Actions
	ghostDeck.push_back(new ShadyAction(owner));
	ghostDeck.push_back(new SeanceAction(owner));
	ghostDeck.push_back(new AcrossTheDivide(owner));
	ghostDeck.push_back(new DeadRiseAction(owner));
	ghostDeck.push_back(new DoorToBeyond(owner));
	ghostDeck.push_back(new MakeContact(owner));

	for (int i = 0; i < 2; i++)
	{
		ghostDeck.push_back(new IncorporealAction(owner));
		ghostDeck.push_back(new GhostlyAction(owner));
	}

	return ghostDeck;
}

std::vector<Card *> DeckConstructor::addShapeShifters(Player *owner)
{
	std::vector<Card *> shapeDeck;

	//Minions
	for (int i = 0; i < 4; i++)
	{
		shapeDeck.push_back(new CopycatMinion(owner));
	}

	for (int i = 0; i < 3; i++)
	{
		shapeDeck.push_back(new MimicMinion(owner));
	}

	for (int i = 0; i < 2; i++)
	{
		shapeDeck.push_back(new GelfMinion(owner));
	}
	shapeDeck.push_back(new DoppelgangerMinion(owner));
	
	//Actions
	shapeDeck.push_back(new SpliceAsNiceAction(owner));
	shapeDeck.push_back(new ReallyAction(owner));
	shapeDeck.push_back(new MitosisAction(owner));
	shapeDeck.push_back(new ShellGameAction(owner));
	shapeDeck.push_back(new CellularBonding(owner));

	for (int i = 0; i < 2; i++)
	{
		shapeDeck.push_back(new Transmogrify(owner));
		shapeDeck.push_back(new GeneticShift(owner));
	}

	return shapeDeck;
}

std::vector<Card *> DeckConstructor::addPirates(Player *owner)
{
	std::vector<Card *> pirateDeck;

	//Minions
	for (int i = 0; i < 4; i++)
	{
		pirateDeck.push_back(new FirstMateMinion(owner));
	}
	
	for (int i = 0; i < 3; i++)
	{
		pirateDeck.push_back(new SaucyWenchMinion(owner));
	}

	for (int i = 0; i < 2; i++)
	{
		pirateDeck.push_back(new BuccaneerMinion(owner));
	}
	pirateDeck.push_back(new PirateKingMinion(owner));
	
	//Actions
	for (int i = 0; i < 2; i++)
	{
		pirateDeck.push_back(new DinghyAction(owner));
	}

	return pirateDeck;
}