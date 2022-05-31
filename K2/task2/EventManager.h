#ifndef __EVENT_MANAGER_H
#define __EVENT_MANAGER_H

#include "Event.h"
#include <iostream>

class EventManager
{
private:
    Event** mEvents;
    size_t mSize;
    size_t mCapacity;

    void copy(const EventManager& other);
    void erase();

public:
    EventManager(const size_t& capacity);
    EventManager(const EventManager& other);
    EventManager& operator=(const EventManager& other);
    ~EventManager();

    bool addEvent(Event*& event);
    ushort ongoingEvents(const Time& currentTime);
};

#endif