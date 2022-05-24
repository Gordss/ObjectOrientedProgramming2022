#ifndef __CAR_H
#define __CAR_H
#include "Vehicle.h"
#include <cstring>

class Car : virtual public Vehicle {
    size_t numTravellers;
    bool isMannerly;
public:
    Car(std::string, size_t, bool);

    virtual double getPrice() const;
    virtual Vehicle* clone() const;
};

#endif