#ifndef __MANAGER_H
#define __MANAGER_H

#include "Specialist.h"
#include <vector>

class Manager : protected Specialist
{
private:
    void copy(const std::vector<Employee*>& empl);
    void erase();
    std::string mDepartmentInfo;
    std::vector<Employee*> mEmployees;

public:
    Manager(const std::string& name,
             const std::string& address,
             const std::string& department,
             const std::string& jobSpecialty,
             const std::string& departmentInfo,
             const size_t& egn,
             const double& salary,
             const std::vector<Employee*> employees);

    Manager(const Manager& other);
    Manager& operator=(const Manager& other);
    ~Manager();

    virtual Employee* clone() const override;
    virtual void print() const override;
};

#endif