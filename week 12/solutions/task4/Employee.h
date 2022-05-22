#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include "Person.h"
#include <iostream>
#include <cstring>

class Employee : public Person {
    std::string mPosition;
public:
    Employee(long, std::string, std::string);

    std::string getPosition() const;
};

#endif