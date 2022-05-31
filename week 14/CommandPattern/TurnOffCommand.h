#ifndef __TURN_OFF_COMMAND_H
#define __TURN_OFF_COMMAND_H

#include "ICommand.h"
#include "Receiver.h"
class TurnOffCommand : public ICommand
{
private:
	Receiver &mReceiver;

public:
	TurnOffCommand(Receiver &);

	void execute() override;

	std::string toString() const override;
};

#endif