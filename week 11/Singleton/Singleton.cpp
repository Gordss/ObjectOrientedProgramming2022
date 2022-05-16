#include "Singleton.h"

Singleton* Singleton::mInstance = nullptr;

Singleton::Singleton() : mCounter(0)
{
	std::cout << "Singleton instance created!\n";
}

Singleton* Singleton::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new Singleton();
	}

	return mInstance;
}

void Singleton::free()
{
	delete mInstance;
}

void Singleton::increase()
{
	this->mCounter++;
}

void Singleton::print() const
{
	std::cout << "Successfully accessed a singleton, yay\n";
}

int Singleton::getCounter() const
{
	return this->mCounter;
}

