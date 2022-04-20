#ifndef __EMAIL_H
#define __EMAIL_H

#include "Date.h"

class Email
{
private:
    Date* mCreateDate;
    char* mCreatorName;
    char* mReceiverName;
    Date* mLastReadDate;
    char* mFileName;
    char* mContent;

    void copy(const Email&);
    void erase();
public:
    Email();
    Email(const char* creator, const char* receiver, const char* content);
    Email(const Email&);
    Email& operator=(const Email&);
    ~Email();

    void setFileName(const char*);
    void updateReadDate();
    void display();
    static Email* open(const char* filename);
    void save();
};

#endif