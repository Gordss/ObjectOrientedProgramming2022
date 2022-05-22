#include "Specialist.h"
#include <iostream>

Specialist::Specialist(
    const std::string& name,
             const std::string& address,
             const std::string& department,
             const std::string& jobSpecialty,
             const size_t& egn,
             const double& salary
) : Employee(name, address, department, egn, salary),
    mJobSpecialty(jobSpecialty)
{
}

Employee* Specialist::clone() const
{
    return new Specialist(*this);
}

void Specialist::print() const
{
    Employee::print();
    std::cout << "JobSpecialty: " << this->mJobSpecialty << '\n';
}