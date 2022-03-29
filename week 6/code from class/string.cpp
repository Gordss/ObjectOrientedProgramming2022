#include <cstring>
#include "string.h"

char* String::allocateMemory(const char* s, size_t capacity)
{
    char* result = new char[capacity];
    strcpy(result, s);

    return result;
}

String::String() : mCapacity(DEFAULT_CAPACITY)
{
    this->mData = new char[mCapacity + 1];
    this->mData[0] = 0;
}

String::String(const String& other)
{
    this->mCapacity = other.mCapacity;
    this->mData = allocateMemory(other.mData, this->mCapacity);
}

String::String(const char* other) : mCapacity(DEFAULT_CAPACITY)
{
    size_t stringSize = strlen(other);
    while((3 * this->mCapacity) / 4 < stringSize)
    {
        this->mCapacity *= 2;
    }

    this->mData = allocateMemory(other, this->mCapacity);
}

String& String::append(const char* other)
{
    for(size_t i = 0; i < strlen(other); i++)
    {
        this->pushBack(other[i]);
    }

    return *this;
}

String& String::operator+=(const String& other)
{
    return this->append(other);
}