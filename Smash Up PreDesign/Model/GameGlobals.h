#pragma once
#include <assert.h>

class Board;

extern Board *vBoard;

enum Faction
{
	PIRATE,
	ZOMBIE,
	GHOST,
	SHAPE_SHIFTER,
	BEAR_CAVALRY
};