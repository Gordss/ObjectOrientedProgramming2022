#include <iomanip>
#include "Building.h"

Building::Building(const size_t& height,
             const double& space,
             const std::string& address)
             : mHeight(height),
             mSpace(space),
             mAddress(address)
{
}

double Building::getHeight() const
{
    return this->mHeight;
}

void Building::print() const
{
    std::cout << "Height: " << this->mHeight << '\n'
              << "Space: " << std::fixed << std::setprecision(2) << this->mSpace << '\n'
              << "Address: " << this->mAddress << '\n';
}

Building Building::initFromConsole()
{
    size_t height;
    std::cout << "Input building height:";
    std::cin >> height;

    double space;
    std::cout << "Input building space:";
    std::cin >> space;

    std::string address;
    std::cout << "Input building address:";
    std::cin >> address;

    return Building(height, space, address);
}