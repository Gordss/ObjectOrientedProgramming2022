#include "QuitCommand.h"

QuitCommand::QuitCommand(Receiver &receiver)
	: mReceiver(receiver)
{
}

void QuitCommand::execute()
{
	throw "quit";
}

std::string QuitCommand::toString() const
{
	return "quit";
}