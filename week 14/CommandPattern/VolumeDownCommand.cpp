#include "VolumeDownCommand.h"

VolumeDownCommand::VolumeDownCommand(Receiver &receiver)
	: mReceiver(receiver)
{
}

void VolumeDownCommand::execute()
{
	this->mReceiver.volumeDown();
}

std::string VolumeDownCommand::toString() const
{
    return "volume-down";
}