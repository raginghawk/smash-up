#pragma once
class Base;

class MinionPlayableStruct
{
public:
	MinionPlayableStruct(int maxPower, Base *base);
	Base *base();
	int maxPower();
private:
	int _maxPower;
	Base *_base;
};