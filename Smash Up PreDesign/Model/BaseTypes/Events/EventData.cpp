#include "EventData.h"

EventData::EventData(EventType eventType)
{
	_eventType = eventType;
}

EventData::EventData(Base *base, EventType eventType)
{
	_base = base;
	_eventType = eventType;
}

EventType EventData::eventType()
{
	return _eventType;
}

Base * EventData::base()
{
	return _base;
}

void EventData::setBase(Base *base)
{
	_base = base;
}
