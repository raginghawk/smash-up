#pragma once
#include <assert.h>
#include <EventData.h>

class EventListener
{
public:
	virtual void call(EventData *eventData);
};