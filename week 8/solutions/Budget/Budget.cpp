#include "Budget.h"

double Budget::mUniBudget = 0.0;

std::ostream& operator<<(std::ostream& os, const Budget& budget) {
    os << "Faculty budget is: " << budget.mFacultyBudget << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, const Budget& budget) {
    std::cout << "Enter faculty budget: " << budget.mFacultyBudget;
    is >> budget.mFacultyBudget;
    return is;
}

Budget& Budget::operator+=(double sum) {
    this->mFacultyBudget += sum;
    return *this;
}

Budget& Budget::operator-=(double sum) {
    this->mFacultyBudget -= sum;
    return *this;   
}

bool Budget::operator==(const Budget& rhs) const {
    return this->mFacultyBudget == rhs.mFacultyBudget;
}

bool Budget::operator!=(const Budget& rhs) const {
    return !(*this == rhs);
}

Budget::Budget()
{
    mFacultyBudget = 0.0;
    mUniBudget += mFacultyBudget;
}

Budget::Budget(double facultyBudget)
{
    mFacultyBudget = facultyBudget;
    mUniBudget += mFacultyBudget;
}

void Budget::addToBudget(double sum)
{
    mFacultyBudget += sum;
    mUniBudget += mFacultyBudget;
}

void Budget::addFromAdministration(double sum)
{
    mUniBudget += sum;
}

double Budget::getFacultyBydget() const
{
    return mFacultyBudget;
}

double Budget::getUniversityBudget() const
{
    return mUniBudget;
}
