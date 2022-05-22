#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <string>
#include <vector>

class Employee
{
private:
    std::string mName;
    std::string mAddress;
    std::string mDepartment;
    size_t mEGN;
    double mSalary; 

public:
    Employee(const std::string& name,
             const std::string& address,
             const std::string& department,
             const size_t& egn,
             const double& salary);

    double getSalary() const;
    virtual Employee* clone() const;
    std::string getName() const;
    virtual void print() const;
};

#endif