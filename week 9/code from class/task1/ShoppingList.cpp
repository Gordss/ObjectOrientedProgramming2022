#include "ShoppingList.h"

#include <cstring>

void ShoppingList::copy(const ShoppingList& other)
{
    this->mSize = other.mSize;
    this->mItems = new ShoppingItem*[this->mSize];

    for(size_t i = 0; i < this->mSize; i++)
    {
        this->mItems[i] = new ShoppingItem(*(other.mItems[i]));
    }
}

void ShoppingList::erase()
{
    for(size_t i = 0; i < this->mSize; i++)
    {
        delete this->mItems[i];
    }

    delete[] this->mItems;
}

ShoppingList::ShoppingList(const size_t size) : mSize(size)
{
    this->mItems = new ShoppingItem*[this->mSize];
}

ShoppingList::ShoppingList(const ShoppingList& other)
{
    this->copy(other);
}

ShoppingList& ShoppingList::operator=(const ShoppingList& other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }

    return *this;
}

ShoppingList::~ShoppingList()
{
    this->erase();
}

void ShoppingList::addItem(const ShoppingItem& item)
{
    bool exists = false;
    size_t index = 0;

    for(size_t i = 0; i < this->mSize; i++)
    {
        if (strcmp(this->mItems[i]->getName(), item.getName()) == 0)
        {
            exists = true;
            index = i;
            break;
        }
    }

    if (exists)
    {
        this->mItems[index]->setCount(this->mItems[index]->getCount() + 1);
    }
    else
    {
        this->mItems[this->mSize++] = new ShoppingItem(item);
    }
}

double ShoppingList::totalPrice() const
{
    double result = 0;

    for(size_t i = 0; i < this->mSize; i++)
    {
        result += this->mItems[i]->calculateTotal();
    }

    return result;
}

const ShoppingItem* ShoppingList::mostExpensive() const
{
    if (this->mSize == 0)
    {
        return nullptr;
    }

    ShoppingItem* result = this->mItems[0];
    for(size_t i = 1; i < this->mSize; i++)
    {
        if(result->getPrice() < this->mItems[i]->getPrice())
        {
            // pointer aritmetics
            result = this->mItems[i];

            // ShoppingItem::operator=()
            // *result = *(this->mItems[i]);
        }
    }

    return result;
}