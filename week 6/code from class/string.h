#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#define DEFAULT_CAPACITY 8

class String
{
private:
    char *mData;
    size_t mCapacity;

    char* allocateMemory(const char*, size_t);
public:
    String();
    String(const String&);
    String(const char*);
    String& operator=(const String&);
    ~String();

    size_t getSize() const;
    size_t getCapacity() const;
    String& append(const String&);
    String& append(const char*);
    void pushBack(char);
    void erase();
    bool isEmpty() const;
    String& swap(String&);
    String* substring(size_t start, size_t end) const;

    String& operator+(const String&);
    String& operator+=(const String&);

    char operator[](size_t) const;
    char& operator[](size_t);

    bool operator!=(const String&);
    bool operator==(const String&);
};

#endif