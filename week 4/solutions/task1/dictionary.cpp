#ifndef __DICTIONARY_CPP
#define __DICTIONARY_CPP

#include <iostream>
#include <cstring>
#include "dictionary.h"

void Dictionary::init(Record *records, int size)
{
    int index = 0;
    bool success;
    this->mSize = 0;

    do
    {
        this->add(records[index++]);
    } while (index < size && index < MAX_CAPACITY);
}

void Dictionary::print() const
{
    std::cout << "\n---------------DICTIONARY---------------\n";

    for (size_t i = 0; i < this->mSize; i++)
    {
        this->mData[i].print();
    }

    std::cout << "\n----------------------------------------\n";
}

bool Dictionary::add(const Record &rec)
{
    if (this->mSize >= MAX_CAPACITY)
    {
        return false;
    }
    else
    {
        this->mData[this->mSize] = rec.copy();
        this->mSize++;
        return true;
    }
}

bool Dictionary::remove(const char *word)
{
    int index = -1;

    for (size_t i = 0; i < this->mSize; i++)
    {
        if (strcmp(this->mData[i].mWord, word) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return false;
    }
    else
    {
        for (size_t i = index; i < this->mSize - 1; i++)
        {
            std::swap(this->mData[i], this->mData[i + 1]);
        }

        this->mData[mSize - 1].deleteDynamic();
        this->mSize--;
        return true;
    }
}

char *Dictionary::findMeaning(const char*word) const
{
    char *result = nullptr;

    for (size_t i = 0; i < this->mSize; i++)
    {
        if (strcmp(this->mData[i].mWord, word) == 0)
        {
            result = new char[strlen(this->mData[i].mMeaning) + 1];
            strcpy(result, this->mData[i].mMeaning);
            break;
        }
    }

    return result;
}

char *Dictionary::getByIndex(int index) const
{
    if (index >= this->mSize)
    {
        return nullptr;
    }

    char *result = new char[strlen(this->mData[index].mMeaning) + 1];
    strcpy(result, this->mData[index].mMeaning);

    return result;
}

void Dictionary::sort()
{
    for (size_t i = 0; i < this->mSize - 1; i++)
    {
        for (size_t j = 0; j < this->mSize - i - 1; j++)
        {
            if (strcmp(this->mData[j].mWord,
                       this->mData[j + 1].mWord) > 0)
            {
                std::swap(this->mData[j], this->mData[j + 1]);
            }
        }
    }
}

void Dictionary::deleteDynamic()
{
    for(int i = 0; i < this->mSize; i++)
    {
        this->mData[i].deleteDynamic();
    }
}

#endif