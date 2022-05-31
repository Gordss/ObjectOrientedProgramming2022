#include "PrintStatusCommand.h"

PrintStatusCommand::PrintStatusCommand(Receiver &receiver)
    : mReceiver(receiver)
{
}

void PrintStatusCommand::execute()
{
    this->mReceiver.printStatus();
}

std::string PrintStatusCommand::toString() const
{
    return "status";
}