#pragma once

class Book {
	int mSerialNumber;
public:
	Book(int serialNumber);

	int getSerialNumber() const;

	void setSerialNumber(int serialNumber);
};