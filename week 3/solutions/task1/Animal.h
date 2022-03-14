#ifndef ANIMAL_H
#define ANIMAL_H

#include <fstream>

enum AnimalType
{
    MAMMAL = 1,
    REPTILE,
    FISH,
    BIRD,
    AMPHIBIAN,
    IVERTEBRATES,
    INSECT
};

struct Animal
{
    AnimalType mType;
    char* mName;
    unsigned short mAge;

    void initialize();
    void loadFromSteam(std::istream& in);
    void writeToStream(std::ostream& out);

    void deleteDynamic();
};

#endif