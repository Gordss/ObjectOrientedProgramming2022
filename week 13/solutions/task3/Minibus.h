#ifndef __MINIBUS_H
#define __MINIBUS_H
#include "Car.h"
#include "Truck.h"
#include <cstring>

class Minibus : public Car, public Truck {
    size_t numDoors;
public:
    Minibus(std::string, size_t, bool, double, size_t);

    virtual double getPrice() const;
    virtual Vehicle* clone() const;
};

#endif