#include "Person.h"

Person::Person(long egn, std::string name) {
    mEGN = egn;
    mName = name;
}

std::string Person::getName() const {
    return mName;
}

long Person::getEgn() const {
    return mEGN;
}