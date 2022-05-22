#ifndef __CEO_H
#define __CEO_H

#include "Employee.h"
#include "Secretary.h"
#include <vector>

class CEO : protected Employee
{
private:
    void copy(const std::vector<Employee*>& empl);
    void erase();
    Employee* mSecretary;
    std::vector<Employee*> mEmployees;

public:
    CEO(const std::string& name,
             const std::string& address,
             const std::string& department,
             const size_t& egn,
             const double& salary,
             const Employee* secretary,
             const std::vector<Employee*>& employees);
    CEO(const CEO& other);
    CEO& operator=(const CEO& other);
    ~CEO();

    double calculateTotalSalary() const;

    virtual Employee* clone() const override;
    virtual void print() const override;
};

#endif