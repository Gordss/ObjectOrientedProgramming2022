#pragma once
#include <string>

class Person {
	std::string mName;
	int mId;
public:
	Person(std::string name, int id);

	std::string getName() const;
	int getId() const;

	void setName(std::string name);
	void setId(int id);
};