#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include "Time.h"

class Date
{
private:
	int mYear;
	char* mMonth;
	int mDay;
	Time mTime;

public:
	Date();
	Date(const int year, const char* month, const int day, const Time& time);
	Date(const Date&);
	Date& operator=(const Date&);
	~Date();

	static Date* readDate(std::istream&);
	static Date* readDateBinary(std::istream&);

	void writeDate(std::ostream&);
	void writeDateBinary(std::ostream&);

	static Date* getCurrentDate();
};

#endif