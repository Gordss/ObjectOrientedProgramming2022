#ifndef __PERSON_H
#define __PERSON_H
#include <cstring>
#include <iostream>

class Person {
    long mEGN;
    std::string mName;
public:
    Person(long, std::string);

    std::string getName() const;
    long getEgn() const;
};

#endif