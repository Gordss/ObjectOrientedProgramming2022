#include "Person.h"

Person::Person(std::string name, int id)
{
	mName = name;
	mId = id;
}

std::string Person::getName() const
{
	return mName;
}

int Person::getId() const
{
	return mId;
}

void Person::setName(std::string name)
{
	mName = name;
}

void Person::setId(int id)
{
	mId = id;
}
