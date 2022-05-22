#ifndef __SECRETARY_H
#define __SECRETARY_H

#include <string>
#include <vector>
#include "Employee.h"

class Secretary : protected Employee
{
private:
    std::vector<std::string> mLanguages;
public:
    Secretary(const std::string& name,
             const std::string& address,
             const std::string& department,
             const size_t& egn,
             const double& salary,
             const std::vector<std::string>& languages);

    virtual Employee* clone() const override;
    virtual void print() const override;
};

#endif