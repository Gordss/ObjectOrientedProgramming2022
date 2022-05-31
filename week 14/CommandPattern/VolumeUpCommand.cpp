#include "VolumeUpCommand.h"

VolumeUpCommand::VolumeUpCommand(Receiver &receiver)
	: mReceiver(receiver)
{
}

void VolumeUpCommand::execute()
{
	this->mReceiver.volumeUp();
}

std::string VolumeUpCommand::toString() const
{
	return "volume-up";
}