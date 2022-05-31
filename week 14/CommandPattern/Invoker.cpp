#include "Invoker.h"

Invoker::Invoker() : mCommands(std::vector<ICommand*>())
{
}

Invoker::Invoker(const std::vector<ICommand*> commands)
	: mCommands(commands)
{
}

Invoker::~Invoker()
{
	for (size_t i = 0; i < this->mCommands.size(); i++)
	{
		delete this->mCommands[i];
	}

	this->mCommands.clear();
}

void Invoker::addCommand(ICommand*&& command)
{
	this->mCommands.push_back(std::move(command));
}

void Invoker::execute(const std::string& commandName)
{
	for (size_t i = 0; i < this->mCommands.size(); i++)
	{
		if (this->mCommands[i]->toString() == commandName)
		{
			this->mCommands[i]->execute();
			return;
		}
	}

	throw "Not supported command!\n";
}