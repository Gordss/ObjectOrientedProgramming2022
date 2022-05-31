#ifndef __PRINT_STATUS_COMMAND_H
#define __PRINT_STATUS_COMMAND_H

#include "ICommand.h"
#include "Receiver.h"

class PrintStatusCommand : public ICommand
{
private:
    Receiver &mReceiver;

public:
    PrintStatusCommand(Receiver &);

    void execute() override;
    std::string toString() const override;
};

#endif