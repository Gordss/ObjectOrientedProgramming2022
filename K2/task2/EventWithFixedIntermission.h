#ifndef __EVENT_WITH_FIXED_INTERMISSION_H
#define __EVENT_WITH_FIXED_INTERMISSION_H

#define MAX_FIXED_EVENT_DURATION 260
#include "Event.h"

class EventWithFixedIntermission : public Event
{
private:
    Time mPause;
public:
    EventWithFixedIntermission(
        const Time& start,
        const Time& pause,
        const Time& end
    );

    virtual bool isOnGoing(const Time& currentTime) const override;
    virtual Event* clone() const override;
};

#endif