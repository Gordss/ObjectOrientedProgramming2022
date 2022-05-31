#ifndef __EVENT_H
#define __EVENT_H

#include "Time.h"

class Event
{
private:
    Time mStart;
    Time mEnd;

public:
    Event(const Time &start,
          const Time &end,
          ushort maxDurationTime);

    Time getStartTime() const;
    Time getEndTime() const;

    void setEndTime(const Time& end);
    void setEndTime(Time&& end);

    virtual bool isOnGoing(const Time& currentTime) const;
    virtual Event* clone() const = 0;
};

#endif