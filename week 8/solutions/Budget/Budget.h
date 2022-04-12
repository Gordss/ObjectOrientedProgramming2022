#pragma once
#include <fstream>
#include <iostream>

class Budget {
	double mFacultyBudget;
	static double mUniBudget;
public:
	Budget();
	Budget(double facultyBudget);
	// No big 4

	void addToBudget(double sum);
	static void addFromAdministration(double sum);

	double getFacultyBydget() const;
	double getUniversityBudget() const;

	friend std::ostream& operator<<(std::ostream& os, const Budget& budget);
	friend std::istream& operator>>(std::istream& os, const Budget& budget);

	Budget& operator+=(double sum);
	Budget& operator-=(double sum);

	bool operator==(const Budget& rhs) const;
	bool operator!=(const Budget& rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Budget& budget);
std::istream& operator>>(std::istream& os, const Budget& budget);
