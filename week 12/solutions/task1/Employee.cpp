#include "Employee.h"
#include <iostream>
#include <iomanip>

Employee::Employee(
    const std::string& name,
             const std::string& address,
             const std::string& department,
             const size_t& egn,
             const double& salary) : mName(name),
             mAddress(address),
             mDepartment(department),
             mEGN(egn),
             mSalary(salary)
{
    if (egn > 10000000000)
    {
        throw "Invalid EGN! Should be max 10 digits!";
    }
}

double Employee::getSalary() const
{
    return this->mSalary;
}

Employee* Employee::clone() const
{
    return new Employee(*this);
}

std::string Employee::getName() const
{
    return this->mName;
}

void Employee::print() const
{
    std::cout << "Name: " << this->mName << '\n'
              << "Address: " << this->mAddress << '\n'
              << "Department: " << this->mDepartment << '\n'
              << "EGN: " << std::setw(10) << std::setfill('0') << this->mEGN << '\n'
              << "Salary:" << std::fixed << std::setprecision(2) << this->mSalary << '\n';
}