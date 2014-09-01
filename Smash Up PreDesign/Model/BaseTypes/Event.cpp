#include "Event.h"


Event::Event(EventType type)
{
	_eventType = type;
}

void Event::fireEvent()
{
	std::vector<EventListener *>::iterator itListeners;
	for (itListeners = _eventListeners.begin(); itListeners != _eventListeners.end(); itListeners++)
	{
		(*itListeners)->call(_eventType);
	}
}

void Event::registerListener(EventListener *eventListener)
{
	_eventListeners.push_back(eventListener);
}

void Event::unregisterListener(EventListener *eventListener)
{
	auto itListener = std::find(_eventListeners.begin(), _eventListeners.end(), eventListener);
	if (itListener == _eventListeners.end())
		assert(true); // Listener not found :/

	_eventListeners.erase(itListener);
}