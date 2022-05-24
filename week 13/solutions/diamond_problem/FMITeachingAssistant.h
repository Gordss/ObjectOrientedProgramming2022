#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Advisor.h"

class FMITeachingAssistant : public Student, public Teacher, public Advisor {
	size_t mNumberOfSubjects;
public:
	FMITeachingAssistant(std::string name, int id, int facNum, size_t numOfStudiedSubjects, std::vector<std::string> subjects, std::vector<std::string> subjectsTheyAdvise);

	size_t getNumberOfSubjects() const;

	void printInfo() const override;
};
