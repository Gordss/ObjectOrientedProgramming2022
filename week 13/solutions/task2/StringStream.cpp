#include "StringStream.h"

StringStream::StringStream(const char* data) : mData(data)
{
}

Stream* StringStream::clone() const
{
    return new StringStream(*this);
}

char StringStream::get()
{
    char result = '\0';
    if (this->mData.size() != 0)
    {
        result = this->mData[0];
        this->mData.erase(this->mData.begin());
    }

    return result;
}