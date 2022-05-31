#ifndef __TURN_ON_COMMAND_H
#define __TURN_ON_COMMAND_H

#include "ICommand.h"
#include "Receiver.h"
class TurnOnCommand : public ICommand
{
private:
	Receiver &mReceiver;

public:
	TurnOnCommand(Receiver &);

	void execute() override;
	std::string toString() const override;
};

#endif