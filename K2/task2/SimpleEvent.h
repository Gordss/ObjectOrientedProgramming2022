#ifndef __SIMPLE_EVENT_H
#define __SIMPLE_EVENT_H

#define MAX_SIMPLE_EVENT_DURATION 120
#include "Event.h"

class SimpleEvent : public Event
{
public:
    SimpleEvent(const Time& start,
                const Time& end);

    virtual Event* clone() const override;
};

#endif