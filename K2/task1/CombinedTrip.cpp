#include "CombinedTrip.h"
#include <cstring>

void CombinedTrip::copy(char **destination, const size_t &size)
{
    this->mDestinations = new char *[size];

    for (size_t i = 0; i < size; i++)
    {
        this->mDestinations[i] = new char[strlen(destination[i]) + 1];
        strcpy(this->mDestinations[i], destination[i]);
    }
}

void CombinedTrip::copy(const CombinedTrip &other)
{
    this->mSize = other.mSize;
    this->copy(other.mDestinations, other.mSize);
    this->mFreeTime = other.mFreeTime;
}

void CombinedTrip::erase()
{
    for (size_t i = 0; i < this->mSize; i++)
    {
        delete[] this->mDestinations[i];
    }

    delete[] this->mDestinations;
}

CombinedTrip::CombinedTrip(
    const char *flightNumber,
    const ushort &flightDuration,
    const ushort *carRegNum,
    const size_t &carDistance,
    const ushort &carDuration,
    char **destinations,
    const size_t &size,
    const ushort &freetime) : AirTravel(flightNumber, flightDuration),
                              CarTravel(carRegNum, carDistance, carDuration),
                              mSize(size),
                              mFreeTime(freetime)
{
    this->copy(destinations, size);
}

CombinedTrip::CombinedTrip(const CombinedTrip& other)
    : AirTravel(other),
      CarTravel(other)
{
    this->copy(other);
}

CombinedTrip& CombinedTrip::operator=(const CombinedTrip& other)
{
    if (this != &other)
    {
        AirTravel::operator=(other);
        CarTravel::operator=(other);
        this->erase();
        this->copy(other);
    }

    return *this;
}

CombinedTrip::~CombinedTrip()
{
    this->erase();
}

ushort CombinedTrip::getDuration() const
{
    return AirTravel::getDuration() + CarTravel::getDuration() + this->mFreeTime;
}

void CombinedTrip::print() const
{
    std::cout << "-----Combined Trip-----\n";
    AirTravel::print();
    CarTravel::print();
    std::cout << "Destinations:\n";
    
    for(size_t i = 0; i < this->mSize; i++)
    {
        std::cout << this->mDestinations[i] << '\n';
    }

    std::cout << "Free time: " << this->mFreeTime << '\n';
}