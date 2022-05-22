#pragma once
#include <iostream>

class PrintedEdition {
protected:
	char* mName;
	size_t mNumPages;
	size_t mId;
	static size_t mIdCounter;

	void copyDynamic(char*& dest, const char* src);
public:
	PrintedEdition();
	PrintedEdition(const char* name, size_t numPages);
	~PrintedEdition();
	PrintedEdition(const PrintedEdition& other);
	PrintedEdition& operator=(const PrintedEdition& other);
	PrintedEdition(PrintedEdition&& other) noexcept;
	PrintedEdition& operator=(PrintedEdition&& other) noexcept;

	char* getName() const;
	size_t getNumberOfPages() const;
	size_t getId() const;

	void setName(const char* name);
	void setNumberOfPages(size_t numberOfPages);

	friend std::ostream& operator<<(std::ostream& out, const PrintedEdition& printedEdition);
};

