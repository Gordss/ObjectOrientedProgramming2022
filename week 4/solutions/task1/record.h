#ifndef __RECORD_H
#define __RECORD_H

struct Record
{
    char* mWord;
    char* mMeaning;

    void init(const char*, const char*);
    Record copy() const;
    void print() const;
    void deleteDynamic();
};

#endif