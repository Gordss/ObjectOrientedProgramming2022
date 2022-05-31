#include "AirTravel.h"
#include <cstring>
#include <iostream>

void AirTravel::copy(const char *flightNumber)
{
    this->mFlightNumber = new char[strlen(flightNumber) + 1];
    strcpy(this->mFlightNumber, flightNumber);
}

void AirTravel::erase()
{
    delete[] this->mFlightNumber;
}

AirTravel::AirTravel(const char *flightNumber,
                     const ushort &duration)
                     : mDuration(duration)
{
    this->copy(flightNumber);
}

AirTravel::AirTravel(const AirTravel& other)
    : mDuration(other.mDuration)
{
    this->copy(other.mFlightNumber);
}

AirTravel& AirTravel::operator=(const AirTravel& other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other.mFlightNumber);
        this->mDuration = other.mDuration;
    }

    return *this;
}

AirTravel::~AirTravel()
{
    this->erase();
}

ushort AirTravel::getDuration() const
{
    return this->mDuration;
}

void AirTravel::print() const
{
    std::cout << "------Air Travel--------\n";
    std::cout << "Flight number: " << this->mFlightNumber << '\n';
    std::cout << "Duration: " << this->mDuration << '\n'; 
}