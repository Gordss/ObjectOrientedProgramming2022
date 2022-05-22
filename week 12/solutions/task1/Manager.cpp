#include "Manager.h"
#include <iostream>

void Manager::copy(const std::vector<Employee*>& empl)
{
    for(size_t i = 0; i < empl.size(); i++)
    {
        this->mEmployees.push_back(empl[i]->clone());
    }
}

void Manager::erase()
{
    for(size_t i = 0; i < this->mEmployees.size(); i++)
    {
        delete this->mEmployees[i];
    }

    this->mEmployees.clear();
}

Manager::Manager(
    const std::string& name,
    const std::string& address,
    const std::string& department,
    const std::string& jobSpecialty,
    const std::string& departmentInfo,
    const size_t& egn,
    const double& salary,
    const std::vector<Employee*> employees
) : Specialist(name, address, department, jobSpecialty, egn, salary),
    mDepartmentInfo(departmentInfo),
    mEmployees(std::vector<Employee*>())
{

    // for(const Employee* employee : employees)
    // {
    //     this->mEmployees.push_back(new Employee(*employee));
    // }

    this->copy(employees);
}

Manager::Manager(const Manager& other)
    : Specialist(other),
    mDepartmentInfo(other.mDepartmentInfo),
    mEmployees(std::vector<Employee*>())
{
    this->copy(other.mEmployees);
}

Manager& Manager::operator=(const Manager& other)
{
    if(this != &other)
    {
        Specialist::operator=(other);
        this->mDepartmentInfo = other.mDepartmentInfo;
        this->erase();
        this->copy(other.mEmployees);
    }

    return *this;
}

Manager::~Manager()
{
    this->erase();
}

Employee* Manager::clone() const
{
    return new Manager(*this);
}

void Manager::print() const
{
    Specialist::print();
    std::cout << "Department info: " << this->mDepartmentInfo << '\n';
    std::cout << "Employee names:\n";
    for(size_t i = 0; i < this->mEmployees.size(); i++)
    {
        std::cout << this->mEmployees[i]->getName() << '\n';
    }
}