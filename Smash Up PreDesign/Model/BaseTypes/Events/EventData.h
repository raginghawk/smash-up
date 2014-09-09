#pragma once
#include <vector>

class Base;

enum EventType
{
	END_OF_TURN,
	BEGINING_OF_TURN,
	BASE_WILL_SCORE,
	BASE_DID_SCORE
};

class EventData
{
public:
	EventData(EventType eventType);
	EventData(Base *base, EventType eventType);

	EventType eventType();
	Base *base();
	void setBase(Base *base);
private:
	EventType _eventType;
	Base *_base;
};