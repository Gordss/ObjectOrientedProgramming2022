#include "EventWithFixedIntermission.h"
#include <iostream>

EventWithFixedIntermission::EventWithFixedIntermission(
    const Time &start,
    const Time &pause,
    const Time &end) : Event(start, end, MAX_FIXED_EVENT_DURATION),
    mPause(pause)
{
    if (this->mPause < start || this->getEndTime() < this->mPause)
    {
        this->mPause = start;
        std::cerr << "Pause time out of duration!\n";
    }
}

bool EventWithFixedIntermission::isOnGoing(const Time& currentTime) const
{
    Time pauseStart = this->mPause;
    Time pauseEnd = this->mPause;
    pauseEnd.addMinutes(20);
    return Event::isOnGoing(currentTime) &&
           (currentTime < pauseStart || pauseEnd < currentTime);  
}

Event* EventWithFixedIntermission::clone() const
{
    return new EventWithFixedIntermission(*this);
}