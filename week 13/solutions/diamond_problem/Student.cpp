#include "Student.h"

Student::Student(std::string name, int id, int facNum, size_t numSubjects) : Person(name, id)
{
	mFacNum = facNum;
	mNumberOfSubjects = numSubjects;
}

int Student::getFacultyNum() const
{
	return mFacNum;
}

size_t Student::getNumberOfSubjects() const
{
	return mNumberOfSubjects;
}

void Student::setFacultyNum(int facNum)
{
	mFacNum = facNum;
}

void Student::setNumSubjects(size_t numSubjects)
{
	mNumberOfSubjects = numSubjects;
}
