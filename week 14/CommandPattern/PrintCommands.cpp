#include "PrintCommands.h"

PrintCommands::PrintCommands(Receiver &receiver)
    : mReceiver(receiver)
{
}

void PrintCommands::execute()
{
    this->mReceiver.printCommands();
}

std::string PrintCommands::toString() const
{
    return "help";
}