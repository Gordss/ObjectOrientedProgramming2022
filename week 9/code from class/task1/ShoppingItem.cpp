#include "ShoppingItem.h"

#include <cstring>

ShoppingItem::ShoppingItem(const char* name, const size_t count, const double price)
{
    if (strlen(name) > 125)
    {
        throw "Name should be 124 chars!\n";
    }

    strcpy(this->mName, name);
    this->mCount = count;
    this->mPrice = price;
}

void ShoppingItem::setName(const char* name)
{
    strcpy(this->mName, name);
}

void ShoppingItem::setCount(const size_t count)
{
    this->mCount = count;
}

void ShoppingItem::setPrice(const double price)
{
    this->mPrice = price;
}

const char* ShoppingItem::getName() const
{
    return this->mName;
}

size_t ShoppingItem::getCount() const
{
    return this->mCount;
}

double ShoppingItem::getPrice() const
{
    return this->mPrice;
}

double ShoppingItem::calculateTotal() const
{
    return this->mCount * this->mPrice;
}