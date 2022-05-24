#include "Garage.h"

Garage::Garage() : vehicles (0, nullptr) {}

Garage::Garage(const std::vector<Vehicle*>& vehicles) {
    this->vehicles = vehicles;
}

Garage& Garage::add(Vehicle* vehicle) {
    vehicles.push_back(vehicle->clone());
    return *this;
}

double Garage::getPaid() const {
    double total = 0.0;
    for(size_t i = 0; i < vehicles.size(); i++) {
        total += vehicles[i]->getPrice();
    }
    return total;
}