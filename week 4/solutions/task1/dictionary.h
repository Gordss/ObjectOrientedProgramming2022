#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include "record.h"
#define MAX_CAPACITY 500


class Dictionary{
private:
    Record mData[MAX_CAPACITY];
    int mSize;
public:
    void init(Record*, int);
    void print() const;
    bool add(const Record&);
    bool remove(const char*);
    char* findMeaning(const char*) const;
    char* getByIndex(int) const;
    void sort();
    void deleteDynamic();
};

#endif