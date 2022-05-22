#pragma once

#include "PrintedEdition.h"

class Book : public PrintedEdition {
	char* mAuthorName;
public:
	Book();
	Book(const char* name, size_t numPages, const char* authorName);
	~Book();
	Book(const Book& other);
	Book& operator=(const Book& other);
	Book(Book&& other) noexcept;
	Book& operator=(Book&& other) noexcept;

	char* getAuthorName() const;

	void setAuthorName(const char* authorName);

	friend std::ostream& operator<<(std::ostream& out, const Book& printedEdition);
};
