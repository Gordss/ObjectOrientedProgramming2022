#ifndef __TIME_H
#define __TIME_H

typedef unsigned short ushort;

struct Time
{
    ushort mHour;
    ushort mMinutes;

    Time& addMinutes(const ushort& minutes);

    friend ushort operator-(const Time& f, const Time& s);
    friend bool operator<(const Time& f, const Time& s);
};

#endif