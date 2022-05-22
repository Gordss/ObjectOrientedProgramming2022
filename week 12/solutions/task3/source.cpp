#include <iostream>
#include <vector>
#include "House.h"

const House* getWithMostAverageHeight(const std::vector<House>& houses)
{
    const House *result = houses.size() != 0 ? &houses[0] : nullptr;
    for (size_t i = 1; i < houses.size(); i++)
    {
        if (result->getFloorAverageHeight() < houses[i].getFloorAverageHeight())
        {
            result = &houses[i];
        }
    }

    return result;
}

int main()
{
    House h1(3, 120, "Sofia", "Rosi", 1),
          h2(8, 80, "Sofia", "Joro", 3);

    House h3 = House::initFromConsole();

    std::vector<House> houses;
    houses.push_back(h1);
    houses.push_back(h2);
    houses.push_back(h3);

    std::cout << "The house with most average height is:\n";
    const House* most = getWithMostAverageHeight(houses);
    most->print();
}