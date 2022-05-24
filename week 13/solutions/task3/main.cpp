#include "Garage.h"
#include "Car.h"
#include "Truck.h"
#include "Minibus.h"
#include <iostream>
#include <time.h>

int main() {
    srand(time(NULL));

    Garage garage;

    garage.add(new Car("CC 1245 AM", 4, true))
          .add(new Truck("CB 1927 YM", 50000))
          .add(new Car("A 1245 AM", 5, false))
          .add(new Minibus("PB 7585 AM", 4, true, 100000, 2));


    std::cout << "Owner of garage will get paid: " << garage.getPaid() << " leva.\n";
    
    // TODOS:
    // - add virtual destructors to classes in hierarchy
    return 0;
}