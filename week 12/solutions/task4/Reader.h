#ifndef __READER_H
#define __READER_H
#include "Person.h"
#include <iostream>
#include <cstring>

class Reader : public Person {
    static long id;
    long mId; //will autogenerate
public:
    Reader(std::string, long);
    long getId() const;
};

#endif