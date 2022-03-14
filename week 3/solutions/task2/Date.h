#ifndef DATE_H
#define DATE_H

#include <fstream>
#include "Time.h"

struct Date
{
	int mYear;
	char* mMonth;
	int mDay;
	Time mTime;

	void readDate(std::ifstream&);
	void readDateBinary(std::ifstream&);

	void writeDate(std::ostream&);
	void writeDateBinary(std::ofstream&);

	void getCurrentDate();
};

#endif