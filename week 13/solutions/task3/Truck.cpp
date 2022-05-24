#include "Truck.h"

Truck::Truck(std::string regnum, double loadCapacity) : Vehicle(regnum) {
    this->loadCapacity = loadCapacity;
}

double Truck::getPrice() const {
    return loadCapacity / 100;
}


Vehicle* Truck::clone() const {
    return new Truck(*this);
}