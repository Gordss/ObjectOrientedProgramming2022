#include "PrintedEdition.h"

size_t PrintedEdition::mCounter = 1;

PrintedEdition::PrintedEdition(std::string name, size_t size) {
    mName = name;
    mSize = size;
    mCounter++;
    mId = mCounter;
    mIsBorrowed = false;
}

bool PrintedEdition::getIsBorrowed() const {
    return mIsBorrowed;
}

void PrintedEdition::setBorrowed(bool borrowed) {
    mIsBorrowed = borrowed;
}

size_t PrintedEdition::getId() const {
    return mId;
}

std::string PrintedEdition::getName() const {
    return mName;
}

size_t PrintedEdition::getSize() const {
    return mSize;
}