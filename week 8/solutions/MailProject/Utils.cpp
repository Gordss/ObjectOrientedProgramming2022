#include <cstring>
#include "Utils.h"

int Utils::convertToInt(char data[2]) {
	int temp1 = (int)data[1] - '0';
	int temp0 = (int)data[0] - '0';

	return (10 * temp0) + temp1;
}

char* Utils::copyDyn(const char* source)
{
	char* result = new char[strlen(source) + 1];
	strcpy(result, source);

	return result;
}