#ifndef __STRINGSTREAM_H
#define __STRINGSTREAM_H

#include "Stream.h"

class StringStream : public Stream
{
private:
    std::string mData;
public:
    StringStream(const char*);

    Stream* clone() const override;
    char get() override;
};

#endif