#ifndef ZOO_H
#define ZOO_H
#include "Animal.h"

struct Zoo
{
    char* mName;
    Animal* mAnimals;
    int mSize;
    int mCapacity;

    void initialize();
    void loadFromStream(std::ifstream& in);
    void writeToStream(std::ostream& out);
    bool hasType(AnimalType type);

    void deleteDynamic();
};

#endif