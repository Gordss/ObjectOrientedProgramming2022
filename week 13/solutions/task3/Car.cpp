#include "Car.h"
#include <time.h>
#include <stdlib.h>

Car::Car(std::string regnum, size_t numTravellers, bool isMannerly) : Vehicle(regnum) {
    this->numTravellers = numTravellers;
    this->isMannerly = isMannerly;
}

double Car::getPrice() const {
    if (isMannerly) {
        return 1.0;
    }

    return 2 + rand() % 9;  
}

Vehicle* Car::clone() const {
    return new Car(*this);
}