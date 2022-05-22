#include "Employee.h"

Employee::Employee(long egn, std::string name, std::string position) : Person(egn, name) {
    mPosition = position;
}

std::string Employee::getPosition() const {
    return mPosition;
}