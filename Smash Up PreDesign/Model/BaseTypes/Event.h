#pragma once

#include <EventListener.h>
#include <vector>

class Event
{
public:
	Event(EventType type);
	void fireEvent();
	void registerListener(EventListener *eventListener);
	void unregisterListener(EventListener *eventListener);
private:
	std::vector<EventListener *> _eventListeners;
	EventType _eventType;
};