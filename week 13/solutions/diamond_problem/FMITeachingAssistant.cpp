#include "FMITeachingAssistant.h"
#include <iostream>

FMITeachingAssistant::FMITeachingAssistant(std::string name, int id, int facNum, size_t numOfStudiedSubjects, std::vector<std::string> subjects, std::vector<std::string> subjectsTheyAdvise) : Person(name, id), Student(name, id, facNum, numOfStudiedSubjects), Teacher(name, id, subjects), Advisor(name, subjectsTheyAdvise)
{
	mNumberOfSubjects = Student::getNumberOfSubjects() + Teacher::getSubjects().size() + Advisor::getSubjects().size();
}

size_t FMITeachingAssistant::getNumberOfSubjects() const
{
	return mNumberOfSubjects;
}

void FMITeachingAssistant::printInfo() const
{
	std::cout << "======================================\n";
	std::cout << "Name: " << Person::getName() << std::endl;
	std::cout << "Id: " << getId() << std::endl;
	std::cout << "Faculty number: " << getFacultyNum() << std::endl;
	std::cout << "Number of studied subjects: " << Student::getNumberOfSubjects() << std::endl;
	std::cout << "Number of subjects they teach: " << Teacher::getSubjects().size() << std::endl;
	for (std::string str : Teacher::getSubjects()) {
		std::cout << str << " ";
	}
	std::cout << "\n";
	std::cout << "Advisor's name: " << Advisor::getName() << std::endl;
	std::cout << "Number of subjects they advise: " << Advisor::getSubjects().size() << std::endl;
	for (std::string str : Advisor::getSubjects()) {
		std::cout << str << " ";
	}
	std::cout << std::endl;
	std::cout << "======================================\n";
}
