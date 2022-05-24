#include "Advisor.h"

Advisor::Advisor(std::string name, std::vector<std::string> subjects)
{
	mName = name;
	mSubjects = subjects;
}

std::string Advisor::getName() const
{
	return mName;
}

std::vector<std::string> Advisor::getSubjects() const
{
	return mSubjects;
}

void Advisor::setName(std::string name)
{
	mName = name;
}

void Advisor::setSubjects(std::vector<std::string> subjects)
{
	mSubjects = subjects;
}
