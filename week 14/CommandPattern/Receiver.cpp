#include "Receiver.h"
#include <iostream>

Receiver::Receiver() : mVolume(50), mOn(false)
{
}

void Receiver::turnOn()
{
	if (isOn())
	{
		std::cout << "The TV is already on" << std::endl;
		return;
	}
	this->mOn = true;
	std::cout << "The TV is now on" << std::endl;
}

void Receiver::turnOff()
{
	if (!isOn())
	{
		std::cout << "The TV is already off" << std::endl;
		return;
	}
	this->mOn = false;
	std::cout << "The TV is now off" << std::endl;
}

void Receiver::volumeUp()
{
	if (++this->mVolume > 100)
	{
		this->mVolume = 100;
		std::cout << "The volume is already at maximum" << std::endl;
		return;
	}
	std::cout << "The volume is now " << this->mVolume << std::endl;
}

void Receiver::volumeDown()
{
	if (--this->mVolume < 0)
	{
		this->mVolume = 0;
		std::cout << "The volume is already at minimum" << std::endl;
		return;
	}
	std::cout << "The volume is now " << this->mVolume << std::endl;
}

bool Receiver::isOn()
{
	return this->mOn;
}

void Receiver::printStatus() const
{
	std::cout << "--------TV--------\n";
	std::cout << "Is on? :" << std::boolalpha << this->mOn << '\n';
	std::cout << "Volume: " << this->mVolume << '\n';
}

void Receiver::printCommands() const
{
	std::cout << "--------USER MANUAL--------\n";
	std::cout << "help => prints the user manual\n";
	std::cout << "status => prints the TV status\n";
	std::cout << "turn-on => turns on the TV\n";
	std::cout << "turn-off => turns off the TV\n";
	std::cout << "volume-up => increases the volume\n";
	std::cout << "volume-down => descreases the volume\n";
}