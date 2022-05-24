#pragma once
#include "Advisor.h"
#include "Book.h"

class SelfHelpBook : public Advisor, public Book {
	std::string mAuthor;
public:
	SelfHelpBook(std::string name, std::vector<std::string> subjects, int serialNumber, std::string author);

	std::string getAuthor() const;

	void setAuthor(std::string author);

	void printInfo() const override;
};
