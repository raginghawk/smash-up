#pragma once

#include <EventListener.h>
#include <vector>

class Event
{
public:
	Event(EventData *data);
	~Event();

	void fireEvent();
	void registerListener(EventListener *eventListener);
	void unregisterListener(EventListener *eventListener);
private:
	std::vector<EventListener *> _eventListeners;
	EventData *_eventData;
};