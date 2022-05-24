#include "Minibus.h"

Minibus::Minibus(std::string reg, size_t numTravellers, bool isMannerly, double loadCapacity, size_t numOfDoors) : Vehicle(reg), Car(reg, numTravellers, isMannerly), Truck(reg, loadCapacity) {
    this->numDoors = numOfDoors;
}

Vehicle* Minibus::clone() const {
    return new Minibus(*this);
}

double Minibus::getPrice() const {
    return (Car::getPrice() + Truck::getPrice()) / 2;
}