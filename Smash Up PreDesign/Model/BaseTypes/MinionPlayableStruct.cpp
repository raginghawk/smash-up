#include "MinionPlayableStruct.h"

MinionPlayableStruct::MinionPlayableStruct(int maxPower, Base *base)
{
	_maxPower = maxPower;
	_base = base;
}

Base * MinionPlayableStruct::base()
{
	return _base;
}

int MinionPlayableStruct::maxPower()
{
	return _maxPower;
}