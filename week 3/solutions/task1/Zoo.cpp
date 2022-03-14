#include <iostream>
#include <cstring>
#include "Zoo.h"
#define INPUT_SIZE 1024

void Zoo::initialize()
{
    char input[INPUT_SIZE];
    std::cout << "Input zoo name:";
    std::cin >> input;

    this->mName = new char[strlen(input) + 1];
    strcpy(this->mName, input);

    std::cout << "Input number of animals:";
    std::cin >> this->mSize;
    this->mCapacity = this->mSize;

    this->mAnimals = new Animal[this->mSize];
    
    try
    {
        for(int i = 0; i < this->mSize; i++)
        {
            this->mAnimals[i].initialize();
        }
    }
    catch(const char* e)
    {
        throw "Couldn't initialize animal!\n";
    }
}

void Zoo::loadFromStream(std::ifstream& in)
{
    int inputSize;
    in >> inputSize;
    this->mName = new char[inputSize + 1];
    char input[INPUT_SIZE];
    in >> input;
    strcpy(this->mName, input);

    in >> this->mCapacity >> this->mSize;

    this->mAnimals = new Animal[this->mCapacity];
    try
    {
        for(int i = 0; i < this->mSize; i++)
        {
            this->mAnimals[i].loadFromSteam(in);
        }
    }
    catch(const char* e)
    {
        throw "Couldn't load animal from stream!\n";
    }
}

void Zoo::writeToStream(std::ostream& out)
{
    out << strlen(this->mName) << ' ' << this->mName << '\n';
    out << this->mCapacity << ' ' << this->mSize << '\n';

    for(int i = 0; i < this->mSize; i++)
    {
        this->mAnimals[i].writeToStream(out);
    }
}

bool Zoo::hasType(AnimalType type)
{
    for (int i = 0; i < this->mSize; i++)
    {
        if (this->mAnimals[i].mType == type)
        {
            return true;
        }
    }

    return false;
}

void Zoo::deleteDynamic()
{
    delete[] this->mName;

    for(int i = 0; i < this->mSize; i++)
    {
        this->mAnimals[i].deleteDynamic();
    }

    delete[] this->mAnimals;
}