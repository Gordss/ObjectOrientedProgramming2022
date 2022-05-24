#pragma once
#include "Person.h"

class Student :  public virtual Person {
	int mFacNum;
	size_t mNumberOfSubjects;
public:
	Student(std::string name, int id, int facNum, size_t numSubjects);

	int getFacultyNum() const;
	size_t getNumberOfSubjects() const;

	void setFacultyNum(int facNum);
	void setNumSubjects(size_t numSubjects);
};
