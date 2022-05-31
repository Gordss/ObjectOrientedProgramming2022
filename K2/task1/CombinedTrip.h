#ifndef __COMBINEDTRIP_H
#define __COMBINEDTRIP_H

#include "AirTravel.h"
#include "CarTravel.h"

class CombinedTrip : public AirTravel, public CarTravel
{
private:
    char **mDestinations;
    size_t mSize;
    ushort mFreeTime;

    void copy(char** destinations, const size_t& size);
    void copy(const CombinedTrip& other);
    void erase();
public:
    CombinedTrip(
        const char* flightNumber,
        const ushort& flightDuration,
        const ushort* carRegNum,
        const size_t& carDistance,
        const ushort& carDuration,
        char** destinations,
        const size_t& size,
        const ushort& freetTime
    );
    CombinedTrip(const CombinedTrip& other);
    CombinedTrip& operator=(const CombinedTrip& other);
    ~CombinedTrip();

    ushort getDuration() const;
    void print() const;
};

#endif