#include "Date.h"
#include <cstring>
#define MAX_DAY_STRING 10

int convertToInt(char data[2]) {
	int temp1 = (int)data[1] - '0';
	int temp0 = (int)data[0] - '0';

	return (10 * temp0) + temp1;
}

void Date::readDate(std::ifstream& in) {
	// dd MMM YYYY, hh:mm
	in >> this->mDay;

	this->mMonth = new char[MAX_DAY_STRING];
	in >> this->mMonth;

	in >> this->mYear;

	in.get(); // for the ,
	in.get(); // for the space

	char temp[2];
	in.get(temp[0]);
	in.get(temp[1]);
	this->mTime.mHours = convertToInt(temp);

	in.get(); // for the :

	in.get(temp[0]);
	in.get(temp[1]);
	this->mTime.mMinutes = convertToInt(temp);
}

void Date::readDateBinary(std::ifstream& in) {
	in.read((char*)&this->mDay, sizeof(int));
	
	int buffSize;
	in.read((char*)&buffSize, sizeof(int));
	this->mMonth = new char[buffSize + 1];
	in.read(this->mMonth, sizeof(char) * buffSize);
	this->mMonth[buffSize] = 0;

	in.read((char*)&this->mYear, sizeof(int));

	in.read((char*)&this->mTime.mHours, sizeof(int));
	in.read((char*)&this->mTime.mMinutes, sizeof(int));
}

void Date::writeDate(std::ostream& out) {
	out << this->mDay << " " << this->mMonth << " " << this->mYear << ", " << this->mTime.mHours << ":" << this->mTime.mMinutes << '\n';
}

void Date::writeDateBinary(std::ofstream& out) {

	out.write((char*)&this->mDay, sizeof(int));
	
	int buffSize = strlen(this->mMonth);
	out.write((char*)&buffSize, sizeof(buffSize));
	out.write(this->mMonth, sizeof(char) * buffSize);

	out.write((char*)&this->mYear, sizeof(int));

	out.write((char*)&this->mTime.mHours, sizeof(int));
	out.write((char*)&this->mTime.mMinutes, sizeof(int));
}

void Date::getCurrentDate()
{
	time_t currentTime;
	tm* currentTimeStruct = new tm;
	time(&currentTime);
	localtime_r(&currentTime, currentTimeStruct);
	
	this->mDay = currentTimeStruct->tm_mday;

	switch(currentTimeStruct->tm_mon)
	{
	    case 0: this->mMonth = (char*)"Jan"; break;
		case 1: this->mMonth = (char*)"Feb"; break;
		case 2: this->mMonth = (char*)"Mar"; break;
		case 3: this->mMonth = (char*)"Apr"; break;
		case 4: this->mMonth = (char*)"Mai"; break;
		case 5: this->mMonth = (char*)"Jun"; break;
		case 6: this->mMonth = (char*)"Jul"; break;
		case 7: this->mMonth = (char*)"Aug"; break;
		case 8: this->mMonth = (char*)"Sep"; break;
		case 9: this->mMonth = (char*)"Oct"; break;
		case 10: this->mMonth = (char*)"Nov"; break;
		case 11: this->mMonth = (char*)"Dec"; break;

		default:
			this->mMonth = (char*)"N/A";
	}
	
	this->mYear = currentTimeStruct->tm_year + 1900;
	this->mTime.mHours = currentTimeStruct->tm_hour;
	this->mTime.mMinutes = currentTimeStruct->tm_min;
}