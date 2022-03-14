#include <iostream>
#include <cstring>
#define INPUT_SIZE 1024
#include "Animal.h"

void Animal::initialize()
{
    std::cout << "Input the animal type\n";
    std::cout << "1 - Mammal\n";
    std::cout << "2 - Reptile\n";
    std::cout << "3 - Fish\n";
    std::cout << "4 - Bird\n";
    std::cout << "5 - Amphibian\n";
    std::cout << "6 - Ivertebrates\n";
    std::cout << "7 - Insect\n";

    int input;
    std::cin >> input;

    if (input < 1 || input > 7)
    {
        throw "Not supported type\n";
    }

    this->mType = (AnimalType)input;

    char in[INPUT_SIZE];
    std::cout << "Input name:\n";
    std:: cin >> in;
    this->mName = new char[strlen(in) + 1];
    strcpy(this->mName, in);

    std::cout << "Input age:\n";
    std::cin >> this->mAge;
}

void Animal::loadFromSteam(std::istream& in)
{
    int input;
    in >> input;

    if (input < 1 || input > 7)
    {
        throw "Not supported type\n";
    }

    this->mType = (AnimalType)input;
    
    in >> input;
    this->mName = new char[input + 1];

    char name[INPUT_SIZE];
    in >> name;
    this->mName = new char[strlen(name) + 1];
    strcpy(this->mName, name);
    in >> this->mAge;
}

void Animal::writeToStream(std::ostream& out)
{
    out << (int)this->mType << '\n';
    out << strlen(this->mName) << ' ' << this->mName << '\n';
    out << this->mAge << '\n';
}

void Animal::deleteDynamic()
{
    delete[] this->mName;
}