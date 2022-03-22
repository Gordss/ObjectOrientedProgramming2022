#include <iostream>
#include <cstring>
#include "record.h"

void Record::init(const char* word, const char* meaning)
{
    this->mWord = new char[strlen(word) + 1];
    strcpy(this->mWord, word);

    this->mMeaning = new char[strlen(meaning) + 1];
    strcpy(this->mMeaning, meaning);
}

Record Record::copy() const
{
    char* wordCopy = new char[strlen(this->mWord) + 1];
    strcpy(wordCopy, this->mWord);

    char* meaningCopy = new char[strlen(this->mMeaning) + 1];
    strcpy(meaningCopy, this->mMeaning);

    return {wordCopy, meaningCopy};
}

void Record::print() const
{
    std::cout << this->mWord << " - " << this->mMeaning << std::endl;
}

void Record::deleteDynamic()
{
    delete[] this->mWord;
    delete[] this->mMeaning;
}