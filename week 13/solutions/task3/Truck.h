#ifndef __TRUCK_H
#define __TRUCK_H
#include "Vehicle.h"
#include <cstring>

class Truck : virtual public Vehicle {
    double loadCapacity; //should probably be long
public:
    Truck(std::string, double);

    virtual double getPrice() const;
    virtual Vehicle* clone() const;
};

#endif