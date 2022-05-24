#ifndef __VEHICLE_H
#define __VEHICLE_H
#include <cstring>
#include <iostream>

class Vehicle {
    const std::string regnum;
public:
    Vehicle(std::string);

    virtual double getPrice() const = 0;
    virtual Vehicle* clone() const = 0;
};

#endif