#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#define DEFAULT_CAPACITY 8

class String
{
private:
    char* mData;
    size_t mCapacity;

    char* dynCopy(const char* other, size_t capacity) const;
    void resize(size_t capacity);
public:
    String();
    String(const char* other);
    String(const String& other);
    String& operator=(const String& other);
    ~String();
    
    size_t size() const;
    size_t capacity() const;
    String& append(const String&);
    String& append(const char*);
    void pushBack(char c);
    void erase();
	bool isEmpty() const;
    
    void swap(String& other);
    String* substring(size_t start, size_t end) const;
	
    String& operator+(const String&)const;
    String& operator+=(const String&);
    char operator[](size_t) const;
    char& operator[](size_t);
    bool operator!=(const String&) const;
    bool operator==(const String&) const;

    friend std::ostream& operator<<(std::ostream&, const String&);
};

#endif