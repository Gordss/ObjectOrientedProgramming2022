#include "House.h"

House::House(const size_t& height,
             const double& space,
             const std::string& address,
             const std::string& owner,
             const size_t& floors)
             : Building(height, space, address),
             mOwner(owner),
             mFloors(floors)
{
}

House::House(const Building& building,
             const std::string& owner,
             const size_t& floors)
             : Building(building),
             mOwner(owner),
             mFloors(floors)
{
}

void House::print() const
{
    std::cout << "Owner name: " << this->mOwner << '\n'
              << "Floors: " << this->mFloors << '\n';

    Building::print();
}

double House::getFloorAverageHeight() const
{
    return this->getHeight() / this->mFloors;
}

House House::initFromConsole()
{
    Building b = Building::initFromConsole();
    std::string owner;
    std::cout << "Input owner name:";
    std::cin >> owner;

    size_t floors;
    std::cout << "Input number of floors:";
    std::cin >> floors;

    return House(b, owner, floors);
}