#pragma once
#include <string>
#include <vector>

class Advisor {
	std::string mName;
	std::vector<std::string> mSubjects;
public:
	Advisor(std::string name, std::vector<std::string> subjects);

	std::string getName() const;
	std::vector<std::string> getSubjects() const;

	void setName(std::string name);
	void setSubjects(std::vector<std::string> subjects);

	virtual void printInfo() const = 0;
};