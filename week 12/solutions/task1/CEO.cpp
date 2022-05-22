#include "CEO.h"
#include <iostream>

void CEO::copy(const std::vector<Employee*>& empl)
{
    for(size_t i = 0; i < empl.size(); i++)
    {
        this->mEmployees.push_back(empl[i]->clone());
    }
}

void CEO::erase()
{
    for(size_t i = 0; i < this->mEmployees.size(); i++)
    {
        delete this->mEmployees[i];
    }

    delete this->mSecretary;
    this->mEmployees.clear();
}

CEO::CEO(const std::string& name,
             const std::string& address,
             const std::string& department,
             const size_t& egn,
             const double& salary,
             const Employee* secretary,
             const std::vector<Employee*>& employees)
             : Employee(name, address, department, egn, salary),
             mSecretary(secretary->clone()),
             mEmployees(std::vector<Employee*>())
{
    copy(employees);
}

CEO::CEO(const CEO& other) : Employee(other), mSecretary(other.mSecretary->clone())
{
    copy(other.mEmployees);
}

CEO& CEO::operator=(const CEO& other)
{
    if(this != &other)
    {
        Employee::operator=(other);
        this->erase();
        this->copy(other.mEmployees);
        this->mSecretary = other.mSecretary->clone();
    }

    return *this;
}

CEO::~CEO()
{
    this->erase();
}

double CEO::calculateTotalSalary() const
{
    double result = 0;
    for(size_t i = 0; i < this->mEmployees.size(); i++)
    {
        result += this->mEmployees[i]->getSalary();
    }

    result += this->mSecretary->getSalary();
    result += this->getSalary();

    return result;
}

Employee* CEO::clone() const
{
    return new CEO(*this);
}

void CEO::print() const
{
    Employee::print();
    std::cout << "Secretary:\n";
    this->mSecretary->print();
    std::cout << "Employees:\n";
    for(size_t i = 0; i < this->mEmployees.size(); i++)
    {
        std::cout << this->mEmployees[i]->getName() << '\n';
    }
}