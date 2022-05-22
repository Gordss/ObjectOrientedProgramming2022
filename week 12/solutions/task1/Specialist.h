#ifndef __SPECIALIST_H
#define __SPECIALIST_H

#include "Employee.h"

class Specialist : protected Employee
{
private:
    std::string mJobSpecialty;
public:
    Specialist(const std::string& name,
             const std::string& address,
             const std::string& department,
             const std::string& jobSpecialty,
             const size_t& egn,
             const double& salary);

    virtual Employee* clone() const override;
    virtual void print() const override;
};

#endif