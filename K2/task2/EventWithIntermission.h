#ifndef __EVENT_WITH_INTERMISSION_H
#define __EVENT_WITH_INTERMISSION_H

#define MAX_INTERMISSION_EVENT_DURATION 360
#define MIN_PAUSE_DURATION 30
#define MAX_PAUSE_DURATION 60

#include "Event.h"

class EventWithIntermission : public Event
{
private:
    Time mPauseStart;
    Time mPauseEnd;
public:
    EventWithIntermission(
        const Time& start,
        const Time& pauseStart,
        const Time& pauseEnd,
        const Time& end
    );

    virtual bool isOnGoing(const Time& currentTime) const override;
    virtual Event* clone() const override;
};

#endif