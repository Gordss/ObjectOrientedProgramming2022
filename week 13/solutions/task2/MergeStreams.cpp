#include "MergeStreams.h"

void MergeStreams::copy(const Stream* a, const Stream* b)
{
    this->mFirst = a->clone();
    this->mSecond = b->clone();
}

void MergeStreams::erase()
{
    delete this->mFirst;
    delete this->mSecond;
}

MergeStreams::MergeStreams(const Stream* a, const Stream* b)
{
    this->mSwitch = InputFrom::FIRST;
    this->copy(a, b);
}

MergeStreams::MergeStreams(const MergeStreams& other)
{
    this->mSwitch = other.mSwitch;
    this->copy(other.mFirst, other.mSecond);
}

MergeStreams& MergeStreams::operator=(const MergeStreams& other)
{
    if (this != &other)
    {
        this->erase();
        this->mSwitch = other.mSwitch;
        this->copy(other.mFirst, other.mSecond);
    }

    return *this;
}

MergeStreams::~MergeStreams()
{
    this->erase();
}

Stream* MergeStreams::clone() const
{
    return new MergeStreams(*this);
}

char MergeStreams::get()
{
    if (this->mSwitch == InputFrom::FIRST)
    {
        this->mSwitch = InputFrom::SECOND;
        return this->mFirst->get();
    }

    this->mSwitch = InputFrom::FIRST;
    return this->mSecond->get();
}