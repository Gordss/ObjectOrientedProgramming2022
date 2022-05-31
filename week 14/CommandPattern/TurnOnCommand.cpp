#include "TurnOnCommand.h"

TurnOnCommand::TurnOnCommand(Receiver &receiver)
	: mReceiver(receiver)
{
}

void TurnOnCommand::execute()
{
	this->mReceiver.turnOn();
}

std::string TurnOnCommand::toString() const
{
	return "turn-on";
}