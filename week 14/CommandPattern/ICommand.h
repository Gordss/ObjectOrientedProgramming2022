#ifndef __ICOMMAND_H
#define __ICOMMAND_H

#include <string>

class ICommand
{
public:
	virtual void execute() = 0;
	virtual std::string toString() const = 0;
};

#endif