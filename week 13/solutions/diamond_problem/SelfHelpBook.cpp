#include "SelfHelpBook.h"
#include <iostream>

SelfHelpBook::SelfHelpBook(std::string name, std::vector<std::string> subjects, int serialNumber, std::string author) : Advisor(name, subjects), Book(serialNumber)
{
	mAuthor = author;
}

std::string SelfHelpBook::getAuthor() const
{
	return mAuthor;
}

void SelfHelpBook::setAuthor(std::string author)
{
	mAuthor = author;
}

void SelfHelpBook::printInfo() const
{
	std::cout << "======================================\n";
	std::cout << "Id: " << getSerialNumber() << "\n";
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Advisor's name: " << Advisor::getName() << std::endl;
	std::cout << "Number of subjects they advise: " << Advisor::getSubjects().size() << std::endl;
	for (std::string str : Advisor::getSubjects()) {
		std::cout << str << " ";
	}
	std::cout << "\n";
	std::cout << "Author: " << mAuthor << "\n";
	std::cout << "======================================\n";
}
