#include "Book.h"
#include "Validator.h"
#include <cstring>

#define NAME_MAX_LEN 32

Book::Book()
{
	mAuthorName = new char[NAME_MAX_LEN];
}

Book::Book(const char* name, size_t numPages, const char* authorName) : PrintedEdition(name, numPages)
{
	try {
		setAuthorName(authorName);
	}
	catch (std::exception& ex) {
		delete[] mAuthorName;

		throw;
	}
}

Book::~Book()
{
	delete[] mAuthorName;
}

Book::Book(const Book& other) : PrintedEdition(other)
{
	copyDynamic(mAuthorName, other.mAuthorName);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other) {
		PrintedEdition::operator=(other);

		copyDynamic(mAuthorName, other.mAuthorName);
	}
	return *this;
}

Book::Book(Book&& other) noexcept : PrintedEdition(other)
{
	copyDynamic(mAuthorName, other.mAuthorName);
	delete[] other.mAuthorName;
}

Book& Book::operator=(Book&& other) noexcept
{
	if (this != &other) {
		PrintedEdition::operator=(other);
		copyDynamic(mAuthorName, other.mAuthorName);
		delete[] other.mAuthorName;
	}
	return *this;
}

char* Book::getAuthorName() const
{
	return mAuthorName;
}

void Book::setAuthorName(const char* authorName)
{
	if (!Validator::validateNotNull(authorName) || !Validator::validateNotEmpty(authorName)) {
		throw std::exception("Invalid argument!");
	}

	copyDynamic(mAuthorName, authorName);
}

std::ostream& operator<<(std::ostream& out, const Book& printedEdition)
{
	out << "---------- BOOK ----------" << '\n';
	out << "Id: " << printedEdition.mId << '\n';
	out << "Edition's name: " << printedEdition.mName << '\n';
	out << "Number of pages: " << printedEdition.mNumPages << '\n';
	out << "Author's name: " << printedEdition.mAuthorName << '\n';
	out << "--------------------------" << '\n';
	return out;
}
