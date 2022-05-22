#ifndef __HOUSE_H
#define __HOUSE_H

#include "Building.h"

class House : protected Building
{
private:
    std::string mOwner;
    size_t mFloors;

public:
    House(const size_t& height,
             const double& space,
             const std::string& address,
             const std::string& owner,
             const size_t& floors);

    House(const Building& building,
          const std::string& owner,
          const size_t& floors);

    void print() const;
    double getFloorAverageHeight() const;
    static House initFromConsole();
};

#endif