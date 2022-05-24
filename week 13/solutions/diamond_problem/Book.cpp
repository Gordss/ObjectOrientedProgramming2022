#include "Book.h"

Book::Book(int serialNumber)
{
	mSerialNumber = serialNumber;
}

int Book::getSerialNumber() const
{
	return mSerialNumber;
}

void Book::setSerialNumber(int serialNumber)
{
	mSerialNumber = serialNumber;
}
