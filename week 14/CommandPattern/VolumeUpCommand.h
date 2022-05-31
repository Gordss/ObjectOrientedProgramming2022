#ifndef __VOLUME_UP_COMMAND_H
#define __VOLUME_UP_COMMAND_H

#include "ICommand.h"
#include "Receiver.h"
class VolumeUpCommand : public ICommand
{
private:
	Receiver &mReceiver;

public:
	VolumeUpCommand(Receiver &);

	void execute() override;
	std::string toString() const override;
};

#endif