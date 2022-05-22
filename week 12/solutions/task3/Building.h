#ifndef __BUILDING_H
#define __BUILDING_H

#include <iostream>
#include <string>

class Building
{
private:
    size_t mHeight;
    double mSpace;
    std::string mAddress;

public:
    Building(const size_t& height,
             const double& space,
             const std::string& address);

    double getHeight() const;
    void print() const;
    static Building initFromConsole();
};

#endif