#include "PrintedEdition.h"
#include "Validator.h"
#include <cstring>

#define NAME_MAX_LEN 32

size_t PrintedEdition::mIdCounter = 0;

void PrintedEdition::copyDynamic(char*& dest, const char* src)
{
	if (dest != nullptr) {
		delete[] dest;
	}

	dest = new char[strlen(src) + 1];
	strcpy(dest, src);
}

PrintedEdition::PrintedEdition()
{
	mName = new char[NAME_MAX_LEN];
	mName[0] = '\0';
	mNumPages = 0;
	mIdCounter++;
	mId = mIdCounter;
}

PrintedEdition::PrintedEdition(const char* name, size_t numPages)
{
	try {
		setName(name);
		mNumPages = numPages;
		mIdCounter++;
		mId = mIdCounter;
	}
	catch (std::exception& ex) {
		delete[] mName;

		throw;
	}
}

PrintedEdition::~PrintedEdition()
{
	delete[] mName;
}

// no need for validation; we have already handled the only way to create an invalid object
PrintedEdition::PrintedEdition(const PrintedEdition& other) 
{
	copyDynamic(mName, other.mName);
	mNumPages = other.mNumPages;
	mIdCounter++;
	mId = mIdCounter;
}

PrintedEdition& PrintedEdition::operator=(const PrintedEdition& other)
{
	if (this != &other) {
		copyDynamic(mName, other.mName);
		mNumPages = other.mNumPages;
		mIdCounter++;
		mId = mIdCounter;
	}
	return *this;
}

PrintedEdition::PrintedEdition(PrintedEdition&& other) noexcept
{
	copyDynamic(mName, other.mName);
	delete[] other.mName;
	mNumPages = other.mNumPages;
	mId = other.mId;
}

PrintedEdition& PrintedEdition::operator=(PrintedEdition&& other) noexcept
{
	if (this != &other) {
		copyDynamic(mName, other.mName);
		delete[] other.mName;

		mNumPages = other.mNumPages;
		mId = other.mId;
	}
	return *this;
}

char* PrintedEdition::getName() const
{
	return mName;
}

size_t PrintedEdition::getNumberOfPages() const
{
	return mNumPages;
}

size_t PrintedEdition::getId() const
{
	return mId;
}

void PrintedEdition::setName(const char* name)
{
	if (!Validator::validateNotNull(name) || !Validator::validateNotEmpty(name)) {
		throw std::exception("Invalid argument!");
	}

	copyDynamic(mName, name);
}

void PrintedEdition::setNumberOfPages(size_t numberOfPages)
{
	mNumPages = numberOfPages;
}

std::ostream& operator<<(std::ostream& out, const PrintedEdition& printedEdition)
{
	out << "----- PRINTED EDITION -----" << '\n';
	out << "Id: " << printedEdition.mId << '\n';
	out << "Edition's name: " << printedEdition.mName << '\n';
	out << "Number of pages: " << printedEdition.mNumPages << '\n';
	out << "----- -------------- -----" << '\n';
	return out;
}
