#pragma once
#include <assert.h>
class Event;

class EventListener
{
public:
	EventListener();
	void call(Event *event);
};

void EventListener::call(Event *event)
{
	assert(true); // should never call the root method
}