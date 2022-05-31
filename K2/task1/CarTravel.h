#ifndef __CARTRAVEL_H
#define __CARTRAVEL_H

#include <iostream>
#include "AirTravel.h"
#define REG_LEN 4

class CarTravel
{
private:
    ushort mRegNum[REG_LEN];
    size_t mDistance;
    ushort mDuration;

public:
    CarTravel(const ushort* regNum,
              const size_t& distance,
              const ushort& duration);

    virtual ~CarTravel() = default;

    ushort getDuration() const;
    void print() const;
};

#endif