#include "Secretary.h"
#include <iostream>

Secretary::Secretary(const std::string& name,
             const std::string& address,
             const std::string& department,
             const size_t& egn,
             const double& salary,
             const std::vector<std::string>& languages)
             : Employee(name, address, department, egn, salary),
             mLanguages(std::vector<std::string>())
{
    this->mLanguages = languages;
}

Employee* Secretary::clone() const
{
    return new Secretary(*this);
}

void Secretary::print() const
{
    Employee::print();
    std::cout << "Languages:\n";
    for(size_t i = 0; i < this->mLanguages.size(); i++)
    {
        std::cout << this->mLanguages[i] << '\n';
    }
}