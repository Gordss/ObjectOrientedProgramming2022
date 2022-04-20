#include "Date.h"
#include "Utils.h"
#include <cstring>
#define MAX_DAY_STRING 4

Date::Date()
{
	this->mYear = 0;
	this->mMonth = nullptr;
	this->mDay = 0;
	this->mTime = {0, 0};
}

Date::Date(const int year, const char* month, const int day, const Time& time)
{
	this->mYear = year;
	this->mMonth = Utils::copyDyn(month);
	this->mDay = day;
	this->mTime = time;
}

Date::Date(const Date& other)
{
	this->mYear = other.mYear;
	this->mMonth = Utils::copyDyn(other.mMonth);
	this->mDay = other.mDay;
	this->mTime = other.mTime;
}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		delete[] this->mMonth;

		this->mYear = other.mYear;
		this->mMonth = Utils::copyDyn(other.mMonth);
		this->mDay = other.mDay;
		this->mTime = other.mTime;
	}

	return *this;
}

Date::~Date()
{
	delete[] this->mMonth;
}

Date* Date::readDate(std::istream& in) {
	// dd MMM YYYY, hh:mm
	Date* result = new Date();

	in >> result->mDay;

	result->mMonth = new char[MAX_DAY_STRING];
	in >> result->mMonth;

	in >> result->mYear;

	in.get(); // for the ,
	in.get(); // for the space

	char temp[2];
	in.get(temp[0]);
	in.get(temp[1]);
	result->mTime.mHours = Utils::convertToInt(temp);

	in.get(); // for the :

	in.get(temp[0]);
	in.get(temp[1]);
	result->mTime.mMinutes = Utils::convertToInt(temp);

	return result;
}

Date* Date::readDateBinary(std::istream& in) {

	Date* result = new Date();
	in.read((char*)&result->mDay, sizeof(int));
	
	int buffSize;
	in.read((char*)&buffSize, sizeof(int));
	result->mMonth = new char[buffSize + 1];
	in.read(result->mMonth, sizeof(char) * buffSize);
	result->mMonth[buffSize] = 0;

	in.read((char*)&result->mYear, sizeof(int));

	in.read((char*)&result->mTime.mHours, sizeof(int));
	in.read((char*)&result->mTime.mMinutes, sizeof(int));

	if (result->mDay == 0 &&
	    result->mYear == 0)
	{
		delete result;
		result = nullptr;	
	}

	return result;
}

void Date::writeDate(std::ostream& out) {
	out << this->mDay << " " << this->mMonth << " " << this->mYear << ", " << this->mTime.mHours << ":" << this->mTime.mMinutes << '\n';
}

void Date::writeDateBinary(std::ostream& out) {

	out.write((char*)&this->mDay, sizeof(int));
	
	int buffSize = strlen(this->mMonth);
	out.write((char*)&buffSize, sizeof(buffSize));
	out.write(this->mMonth, sizeof(char) * buffSize);

	out.write((char*)&this->mYear, sizeof(int));

	out.write((char*)&this->mTime.mHours, sizeof(int));
	out.write((char*)&this->mTime.mMinutes, sizeof(int));
}

Date* Date::getCurrentDate()
{
	time_t currentTime;
	tm* currentTimeStruct = new tm;
	time(&currentTime);
	localtime_r(&currentTime, currentTimeStruct);
	
	const char* month;
	switch(currentTimeStruct->tm_mon)
	{
	    case 0: month = "Jan"; break;
		case 1: month = "Feb"; break;
		case 2: month = "Mar"; break;
		case 3: month = "Apr"; break;
		case 4: month = "Mai"; break;
		case 5: month = "Jun"; break;
		case 6: month = "Jul"; break;
		case 7: month = "Aug"; break;
		case 8: month = "Sep"; break;
		case 9: month = "Oct"; break;
		case 10: month = "Nov"; break;
		case 11: month = "Dec"; break;

		default:
			month = (char*)"N/A";
	}
	
	Date* result = new Date(currentTimeStruct->tm_year + 1900,
							month,
							currentTimeStruct->tm_mday,
						    {currentTimeStruct->tm_hour,
							 currentTimeStruct->tm_min});

	return result;
}