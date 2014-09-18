#include "DeckConstructor.h"
#include <Minions.h>
#include <Actions.h>
#include <algorithm>	/* random_shuffle*/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


std::vector<Card *> DeckConstructor::addDeck(Faction factionToAdd, std::vector<Card *>deck, Player *owner)
{
	std::vector<Card *> newDeck;

	switch (factionToAdd)
	{
	case GHOST:
		newDeck = addGhosts(owner);
		break;
	case SHAPE_SHIFTER:
		newDeck = addShapeShifters(owner);
		break;
	case PIRATE:
		newDeck = addPirates(owner);
		break;
	case BEAR_CAVALRY:
		newDeck = addBears(owner);
		break;
	case ZOMBIE:
		newDeck = addZombies(owner);
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
	for (int c = 0; c < 4; c++)
	{
		ghostDeck.push_back(new GhostMinion(owner));
	}
	for (int c = 0; c < 3; c++)
	{
		ghostDeck.push_back(new SpiritMinion(owner));
	}
	for (int c = 0; c < 2; c++)
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

	for (int c = 0; c < 2; c++)
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
	for (int c = 0; c < 4; c++)
	{
		shapeDeck.push_back(new CopycatMinion(owner));
	}

	for (int c = 0; c < 3; c++)
	{
		shapeDeck.push_back(new MimicMinion(owner));
	}

	for (int c = 0; c < 2; c++)
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

	for (int c = 0; c < 2; c++)
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
	for (int c = 0; c < 4; c++)
	{
		pirateDeck.push_back(new FirstMateMinion(owner));
	}
	
	for (int c = 0; c < 3; c++)
	{
		pirateDeck.push_back(new SaucyWenchMinion(owner));
	}

	for (int c = 0; c < 2; c++)
	{
		pirateDeck.push_back(new BuccaneerMinion(owner));
	}
	pirateDeck.push_back(new PirateKingMinion(owner));
	
	//Actions
	for (int c = 0; c < 2; c++)
	{
		pirateDeck.push_back(new DinghyAction(owner));
	}
	
	for (int c = 0; c < 2; c++)
	{
		pirateDeck.push_back(new BroadsideAction(owner));
	}

	pirateDeck.push_back(new PowderKegAction(owner));
	pirateDeck.push_back(new SwashbucklingAction(owner));
	pirateDeck.push_back(new ShanghaiAction(owner));
	pirateDeck.push_back(new CannonAction(owner));
	pirateDeck.push_back(new SeaDogsAction(owner));
	pirateDeck.push_back(new FullSailAction(owner));

	return pirateDeck;
}

std::vector<Card *> DeckConstructor::addBears(Player *owner)
{
	std::vector<Card *> bearDeck;

	//Minions
	for (int c = 0; c < 3; c++)
	{
		bearDeck.push_back(new BearCavalryMinion(owner));
	}
	
	for (int c = 0; c < 2; c++)
	{
		bearDeck.push_back(new PolarCommandoMinion(owner));
	}

	bearDeck.push_back(new GeneralIvanMinion(owner));

	return bearDeck;

	//TODO FINISH BEARS
}

std::vector<Card *> DeckConstructor::addZombies(Player *owner)
{
	std::vector<Card *> zombieDeck;

	//Minions
	for (int c = 0; c < 4; c++)
	{
		zombieDeck.push_back(new WalkerMinion(owner));
	}

	for (int c = 0; c < 3; c++)
	{
		zombieDeck.push_back(new TenaciousZMinion(owner));
	}

	for (int c = 0; c < 2; c++)
	{
		zombieDeck.push_back(new GraveDiggerMinion(owner));
	}
	zombieDeck.push_back(new ZombieLordMinion(owner));

	return zombieDeck;
}