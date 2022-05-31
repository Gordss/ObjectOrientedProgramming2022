#include "Event.h"
#include <iostream>

Event::Event(
    const Time &start,
    const Time &end,
    ushort maxDurationTime)
    : mStart(start),
      mEnd(end)
{
    if (this->mEnd - this->mStart > maxDurationTime)
    {
        Time newEndTime = this->getStartTime();
        newEndTime.addMinutes(maxDurationTime);
        this->setEndTime(newEndTime);
        std::cerr << "Max event time exceeded!\n";
    }
}

Time Event::getStartTime() const
{
    return this->mStart;
}

Time Event::getEndTime() const
{
    return this->mEnd;
}

void Event::setEndTime(const Time& end)
{
    this->mEnd = end;
}

void Event::setEndTime(Time&& end)
{
    this->mEnd = end;
}

bool Event::isOnGoing(const Time& currentTime) const
{
    return this->mStart < currentTime && currentTime < this->mEnd;
}