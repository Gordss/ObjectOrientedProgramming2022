#pragma once
#include "Person.h"
#include <vector>

class Teacher : public virtual Person {
	std::vector<std::string> mSubjects;
public:
	Teacher(std::string name, int id, std::vector<std::string> subjects);

	std::vector<std::string> getSubjects() const;

	void setSubjects(std::vector<std::string> subjects);
};

// const Teacher t;
// da-> t.getObjects();
// ne -> t.setObjects(...);