#include "Time.h"
#include <cmath>

Time& Time::addMinutes(const ushort& minutes)
{
    ushort increaseHour = (this->mMinutes + minutes) / 60;

    this->mMinutes = (this->mMinutes + minutes) % 60;
    this->mHour = increaseHour != 0 ? this->mHour + increaseHour : this->mHour;

    return *this;
}

ushort operator-(const Time& f, const Time& s)
{  
    ushort a = f.mHour * 60 + f.mMinutes;
    ushort b = s.mHour * 60 + s.mMinutes;
    return abs(a - b);
}

bool operator<(const Time& f, const Time& s)
{
    return f.mHour < s.mHour || (f.mHour == s.mHour && f.mMinutes < s.mMinutes);
}