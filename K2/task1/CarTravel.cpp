#include "CarTravel.h"
#include <iostream>

CarTravel::CarTravel(const ushort *regNum,
                     const size_t &distance,
                     const ushort &duration)
                    : mDistance(distance),
                    mDuration(duration)
{
    for(size_t i = 0; i < REG_LEN; i++)
    {
        this->mRegNum[i] = regNum[i];
    }
}

ushort CarTravel::getDuration() const
{
    return this->mDuration;
}

void CarTravel::print() const
{
    std::cout << "-------Car Travel--------\n";
    std::cout << "Car reg number: ";

    for (ushort i = 0; i < REG_LEN; i++)
    {
        std::cout << this->mRegNum[i];
    }

    std::cout << '\n';
    std::cout << "Distance: " << this->mDistance << '\n';
    std::cout << "Duration: " << this->mDuration << '\n';
}