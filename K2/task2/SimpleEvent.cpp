#include "SimpleEvent.h"
#include <iostream>

SimpleEvent::SimpleEvent(
    const Time &start,
    const Time &end)
    : Event(start, end, MAX_SIMPLE_EVENT_DURATION)
{   
}

Event* SimpleEvent::clone() const
{
    return new SimpleEvent(*this);
}