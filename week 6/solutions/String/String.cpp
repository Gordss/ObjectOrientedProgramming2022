#include "String.h"
#include <cstring>
#include <cmath>

char* String::dynCopy(const char* other, size_t capacity) const
{
    char* result = new char[capacity + 1];
    strcpy(result, other);

    return result;
}

void String::resize(size_t capacity)
{
    char* save = this->mData;
    this->mData = new char[capacity + 1];
    strcpy(this->mData, save);
    delete[] save;
}

String::String() : mCapacity(DEFAULT_CAPACITY)
{
    this->mData = new char[mCapacity + 1];
    this->mData[0] = 0;
}

String::String(const char* other) : mCapacity(DEFAULT_CAPACITY)
{
    size_t stringSize = strlen(other);

    while((mCapacity*3)/4 < stringSize)
    {
        mCapacity *= 2;
    }

    this->mData = dynCopy(other, mCapacity);
}

String::String(const String& other): mCapacity(other.mCapacity)
{
    this->mData = dynCopy(other.mData, mCapacity);
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] this->mData;
        this->mCapacity = other.mCapacity;
        this->mData = dynCopy(other.mData, mCapacity);
    }

    return *this;
}

String::~String()
{
    delete[] this->mData;
}

size_t String::size() const
{
    return strlen(this->mData);
}

size_t String::capacity() const
{
    return this->mCapacity;
}

String& String::append(const String& other)
{
    return this->append(other.mData);
}

String& String::append(const char* other)
{
    bool isDirty = false;
    while ((this->mCapacity*3)/4 < strlen(other) + this->size())
    {
        isDirty = true;
        this->mCapacity *= 2;
    }

    if(isDirty)
    {
        resize(this->mCapacity);
    }

    strcat(this->mData, other);

    return *this;
}

void String::pushBack(char c)
{
    if((this->mCapacity*3)/4 < this->size() + 1)
    {
        mCapacity *= 2;
        this->resize(mCapacity);
    }

    size_t oldSize = this->size();
    this->mData[oldSize] = c;
    this->mData[oldSize + 1] = 0;
}

void String::erase()
{
    if(this->mCapacity != DEFAULT_CAPACITY)
    {
        delete[] this->mData;
        this->mCapacity = DEFAULT_CAPACITY;
        this->mData = new char[this->mCapacity + 1];
    }
    else
    {
        this->mData[0] = 0;
    }
}

bool String::isEmpty() const
{
    return this->size() == 0;
}

void String::swap(String& other)
{
    std::swap(this->mCapacity, other.mCapacity);
    char *temp = this->mData;
    this->mData = other.mData;
    other.mData = temp;
}

String* String::substring(size_t start, size_t end) const
{
    String* result = new String();
    int size = end - start;
    while ((result->mCapacity * 3)/4 < size)
    {
        result->mCapacity *= 2;
    }

    size_t index = 0;
    for (size_t i = start; i < end; i++)
    {
        result->mData[index++] = this->mData[i];
    }
    result->mData[index] = 0;

    return result;
}

String& String::operator+(const String& other) const
{
    String *result = new String(*this);
    return result->append(other);
}

String& String::operator+=(const String& other)
{
    return this->append(other);
}

char String::operator[](size_t index) const
{
    if (index >= this->size())
    {
        throw "Index out of bounds";
    }

    return this->mData[index];
}

char& String::operator[](size_t index)
{
    if (index >= this->size())
    {
        throw "Index out of bounds";
    }

    return this->mData[index];
}

bool String::operator==(const String& other) const
{
    return this->mCapacity == other.mCapacity &&
           strcmp(this->mData, other.mData) == 0;
}

bool String::operator!=(const String& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
    out << s.size() << ' ' <<  s.mData;

    return out;
}