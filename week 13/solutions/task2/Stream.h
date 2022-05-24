#ifndef __STREAM_H
#define __STREAM_H

#include <string>

class Stream
{
public:
    virtual Stream* clone() const = 0;
    virtual char get() = 0;
    virtual std::string take(unsigned n);
};

#endif