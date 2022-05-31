#include <iostream>
#include <cstring>
#include "CombinedTrip.h"

int main()
{
    AirTravel air("FN-133CC82", 120);

    ushort carPlate[] = {0, 0, 0, 1};
    CarTravel car(carPlate, 1500, 300);

    char dest1[] {"Aqaba"}; 
    char dest2[] {"Amman"};
    char dest3[] {"Wadi Rum Desert"};
    char dest4[] {"Dead Sea"};

    char ** destinations = new char*[4];
    destinations[0] = new char[strlen(dest1) + 1];
    strcpy(destinations[0], dest1);
    destinations[1] = new char[strlen(dest2) + 1];
    strcpy(destinations[1], dest2);
    destinations[2] = new char[strlen(dest3) + 1];
    strcpy(destinations[2], dest3);
    destinations[3] = new char[strlen(dest4) + 1];
    strcpy(destinations[3], dest4);

    CombinedTrip trip("FN-133CC82",
                      120,
                      carPlate,
                      1500,
                      300,
                      destinations,
                      4,
                      180);
    
    trip.print();
    std::cout << "Total duration: " << trip.getDuration() << '\n';

    for (int i = 0; i < 4; i++)
    {
        delete[] destinations[i];
    }

    delete[] destinations;
}