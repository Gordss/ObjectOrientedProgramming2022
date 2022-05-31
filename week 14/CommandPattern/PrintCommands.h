#ifndef __PRINT_COMMANDS_H
#define __PRINT_COMMANDS_H

#include "ICommand.h"
#include "Receiver.h"

class PrintCommands : public ICommand
{
private:
    Receiver &mReceiver;

public:
    PrintCommands(Receiver &);

    void execute() override;
    std::string toString() const override;
};

#endif