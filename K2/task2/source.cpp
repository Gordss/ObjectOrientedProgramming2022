#include <iostream>
#include "EventManager.h"
#include "SimpleEvent.h"
#include "EventWithFixedIntermission.h"
#include "EventWithIntermission.h"

int main()
{
    EventManager manager(6);

    Event *event1 = new SimpleEvent(Time{7, 30}, Time{10, 40});
    // end 9:30
    Event *event2 = new SimpleEvent(Time{11, 00}, Time{13, 00});

    Event *event3 = new EventWithFixedIntermission(Time{8, 00}, Time{10, 30}, Time{14, 00});
    // end 12:20
    Event *event4 = new EventWithIntermission(Time{8, 30}, Time{10, 00}, Time{10, 30}, Time{13, 45});

    manager.addEvent(event1);
    manager.addEvent(event2);
    manager.addEvent(event3);
    manager.addEvent(event4);

    std::cout << "On going events: " << manager.ongoingEvents(Time{10, 35}) << '\n';
}