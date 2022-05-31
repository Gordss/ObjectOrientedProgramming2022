#ifndef __AIRTRAVEL_H
#define __AIRTRAVEL_H

typedef unsigned short ushort;

class AirTravel
{
private:
    char *mFlightNumber;
    ushort mDuration;

    void copy(const char *flightNumber);
    void erase();

public:
    AirTravel(const char *flightNumber, const ushort &duration);
    AirTravel(const AirTravel &other);
    AirTravel &operator=(const AirTravel &other);
    virtual ~AirTravel();

    ushort getDuration() const;
    void print() const;
};

#endif