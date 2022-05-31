#include "EventWithIntermission.h"
#include <iostream>

EventWithIntermission::EventWithIntermission(
    const Time &start,
    const Time &pauseStart,
    const Time &pauseEnd,
    const Time &end)
    : Event(start, end, MAX_INTERMISSION_EVENT_DURATION),
    mPauseStart(pauseStart),
    mPauseEnd(pauseEnd)
{
    if (this->mPauseStart < start || this->getEndTime() < this->mPauseStart)
    {
        this->mPauseStart = start;
        std::cerr << "Pause time out of duration!\n";
    }

    if (this->mPauseEnd < this->mPauseStart)
    {
        Time newEndTime = this->mPauseStart;
        this->mPauseEnd = newEndTime.addMinutes(MIN_PAUSE_DURATION);
        std::cerr << "Pause end time is before pause start time!\n";
    }

    if (this->mPauseEnd - this->mPauseStart > MAX_PAUSE_DURATION)
    {
        Time newEndTime = this->mPauseEnd;
        newEndTime.addMinutes(MAX_PAUSE_DURATION);
        this->setEndTime(newEndTime);
        std::cerr << "Max event pause time exceeded!\n";
    }
}

bool EventWithIntermission::isOnGoing(const Time& currentTime) const
{
    bool f = Event::isOnGoing(currentTime);
    bool s = currentTime < this->mPauseStart || this->mPauseEnd < currentTime;

    return Event::isOnGoing(currentTime) &&
           (currentTime < this->mPauseStart || this->mPauseEnd < currentTime);  
}

Event* EventWithIntermission::clone() const
{
    return new EventWithIntermission(*this);
}