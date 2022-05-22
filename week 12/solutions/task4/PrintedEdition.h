#ifndef __PRINTED_EDITION_H
#define __PRINTED_EDITION_H

#include <iostream>
#include <cstring>

class PrintedEdition {
protected:   
    std::string mName;
    size_t mSize;
    static size_t mCounter;
    size_t mId;
    bool mIsBorrowed;
public:
    PrintedEdition(std::string, size_t);

    bool getIsBorrowed() const;
    void setBorrowed(bool);

    size_t getId() const;
    std::string getName() const;
    size_t getSize() const;
};

#endif