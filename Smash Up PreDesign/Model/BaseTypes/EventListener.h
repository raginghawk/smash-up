#pragma once
#include <assert.h>

enum EventType
{
	END_OF_TURN,
	BEGINING_OF_TURN,
};

class EventListener
{
public:
	virtual void call(EventType eventType);
};