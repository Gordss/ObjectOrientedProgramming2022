#ifndef __INVOKER_H
#define __INVOKER_H

#include "ICommand.h"
#include <vector>
#include <string>

//the Invoker in this case is a simple remote control
class Invoker
{
private:
	std::vector<ICommand*> mCommands;

public:
	Invoker();
	Invoker(const std::vector<ICommand*> commands);
	~Invoker();

	void addCommand(ICommand*&& command);

	void execute(const std::string& commandName);
};

#endif