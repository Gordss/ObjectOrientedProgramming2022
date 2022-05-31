#ifndef __ENGINE_H
#define __ENGINE_H

#include "Receiver.h"
#include "Invoker.h"

class Engine
{
private:
    Receiver mTV;
    Invoker mRemoteControl;
public:
    Engine();

    void run();
};

#endif