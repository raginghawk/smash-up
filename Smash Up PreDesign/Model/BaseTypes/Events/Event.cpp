#include "Event.h"


Event::Event(EventData *data)
{
	_eventData = data;
}

Event::~Event()
{
	delete(_eventData);
}

void Event::fireEvent()
{
	std::vector<EventListener *>::iterator itListeners;
	for (itListeners = _eventListeners.begin(); itListeners != _eventListeners.end(); itListeners++)
	{
		(*itListeners)->call(_eventData);
	}
}

void Event::registerListener(EventListener *eventListener)
{
	_eventListeners.push_back(eventListener);
}

void Event::unregisterListener(EventListener *eventListener)
{
	std::vector<EventListener *>::iterator itListener = std::find(_eventListeners.begin(), _eventListeners.end(), eventListener);
	if (itListener == _eventListeners.end())
	{
		assert(false); // Couldn't find minion
	}
	else
		_eventListeners.erase(itListener);
}