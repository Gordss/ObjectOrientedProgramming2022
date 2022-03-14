#include <iostream>
#include <fstream>
#include "Zoo.h"

int main()
{
    Zoo myZoo;

    try
    {
        myZoo.initialize();
    }
    catch (const char* e)
    {
        std::cerr << e << '\n';
        return 1;
    }
    

    std::ofstream outFile("myzoo.anim", std::ios::trunc);
    myZoo.writeToStream(outFile);

    outFile.close();

    std::cout << "\nHas birds in the zoo?\n";
    std::cout << std::boolalpha << myZoo.hasType(AnimalType::BIRD) << '\n';

    Zoo loadedZoo;
    std::ifstream inFile("myzoo.anim");
    try
    {
        loadedZoo.loadFromStream(inFile);
    }
    catch (const char* e)
    {
        std::cerr << e << '\n';
        return 1;
    }
    loadedZoo.writeToStream(std::cout);

    inFile.close();

    myZoo.deleteDynamic();
    loadedZoo.deleteDynamic();
}