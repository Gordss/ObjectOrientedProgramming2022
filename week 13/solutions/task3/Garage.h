#ifndef __GARAGE_H
#define __GARAGE_H
#include "Vehicle.h"
#include <vector>

class Garage {
    std::vector<Vehicle*> vehicles;
public:
    Garage();
    Garage(const std::vector<Vehicle*>&);

    Garage& add(Vehicle*);
    double getPaid() const;
};

#endif