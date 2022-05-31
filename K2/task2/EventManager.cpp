#include "EventManager.h"

void EventManager::copy(const EventManager& other)
{
    this->mCapacity = other.mCapacity;
    this->mSize = other.mSize;
    this->mEvents = new Event*[mSize];
    
    for(size_t i = 0; i < this->mSize; i++)
    {
        this->mEvents[i] = other.mEvents[i]->clone();
    }
}

void EventManager::erase()
{
    for(size_t i = 0; i < this->mSize; i++)
    {
        delete this->mEvents[i];
    }

    delete[] this->mEvents;
}

EventManager::EventManager(const size_t& capacity)
    : mSize(0),
      mCapacity(capacity)
{
    this->mEvents = new Event*[capacity];
}

EventManager::EventManager(const EventManager& other)
{
    this->copy(other);    
}

EventManager& EventManager::operator=(const EventManager& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

EventManager::~EventManager()
{
    this->erase();
}

bool EventManager::addEvent(Event*& event)
{
    if(this->mSize < this->mCapacity)
    {
        this->mEvents[this->mSize++] = event->clone();
        return true;
    }

    return false;
}

ushort EventManager::ongoingEvents(const Time& currentTime)
{
    ushort counter = 0;

    for(size_t i = 0; i < this->mSize; i++)
    {
        if(this->mEvents[i]->isOnGoing(currentTime))
        {
            counter++;
        }
    }

    return counter;
}