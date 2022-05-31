#include "TurnOffCommand.h"

TurnOffCommand::TurnOffCommand(Receiver& receiver)
	: mReceiver(receiver)
{
}

void TurnOffCommand::execute()
{
	this->mReceiver.turnOff();
}

std::string TurnOffCommand::toString() const
{
	return "turn-off";
}