#pragma once

#include "PrintedEdition.h"

class Newspaper : public PrintedEdition {
	size_t mEdNum;
public:
	Newspaper();
	Newspaper(const char* name, size_t numPages, size_t edNum);
	~Newspaper();
	Newspaper(const Newspaper& other);
	Newspaper& operator=(const Newspaper& other);
	Newspaper(Newspaper&& other) noexcept;
	Newspaper& operator=(Newspaper&& other) noexcept;

	size_t getEditionNumber() const;

	void setEditionNumber(size_t edNum);

	friend std::ostream& operator<<(std::ostream& out, const  Newspaper& printedEdition);
};
