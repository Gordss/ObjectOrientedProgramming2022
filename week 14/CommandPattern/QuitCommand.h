#ifndef __QUIT_COMMAND_H
#define __QUIT_COMMAND_H

#include "ICommand.h"
#include "Receiver.h"
class QuitCommand : public ICommand
{
private:
	Receiver &mReceiver;

public:
	QuitCommand(Receiver &);

	void execute() override;
	std::string toString() const override;
};

#endif