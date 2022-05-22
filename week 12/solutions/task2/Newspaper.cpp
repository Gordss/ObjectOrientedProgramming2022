#include "Newspaper.h"

#define DEFAULT_EDITION_NUMBER 0

Newspaper::Newspaper()
{
	mEdNum = DEFAULT_EDITION_NUMBER;
}

Newspaper::Newspaper(const char* name, size_t numPages, size_t edNum) : PrintedEdition(name, numPages)
{
	mEdNum = edNum;
}

Newspaper::~Newspaper()
{
}

Newspaper::Newspaper(const Newspaper& other) : PrintedEdition(other)
{
	mEdNum = other.mEdNum;
}

Newspaper& Newspaper::operator=(const Newspaper& other)
{
	if (this != &other) {
		PrintedEdition::operator=(other);

		mEdNum = other.mEdNum;
	}
	return *this;
}

Newspaper::Newspaper(Newspaper&& other) noexcept : PrintedEdition(other)
{
	mEdNum = other.mEdNum;
	other.mEdNum = DEFAULT_EDITION_NUMBER;
}

Newspaper& Newspaper::operator=(Newspaper&& other) noexcept
{
	if (this != &other) {
		PrintedEdition::operator=(other);
		mEdNum = other.mEdNum;
		other.mEdNum = DEFAULT_EDITION_NUMBER;
	}
	return *this;
}

size_t Newspaper::getEditionNumber() const
{
	return mEdNum;
}

void Newspaper::setEditionNumber(size_t edNum)
{
	mEdNum = edNum;
}

std::ostream& operator<<(std::ostream& out, const Newspaper& printedEdition)
{
	out << "------- NEWSPAPER --------" << '\n';
	out << "Id: " << printedEdition.mId << '\n';
	out << "Edition's name: " << printedEdition.mName << '\n';
	out << "Number of pages: " << printedEdition.mNumPages << '\n';
	out << "Edition's number: " << printedEdition.mEdNum << '\n';
	out << "--------------------------" << '\n';
	return out;
}
