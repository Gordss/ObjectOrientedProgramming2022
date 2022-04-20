#ifndef __SHOPPINGLIST_H
#define __SHOPPINGLIST_H

#include "ShoppingItem.h"

class ShoppingList
{
private:
    ShoppingItem **mItems;
    size_t mSize;
    size_t mCapacity;

    // void resize(const size_t newCapacity);

    void copy(const ShoppingList&);
    void erase();

public:
    ShoppingList(const size_t);
    ShoppingList(const ShoppingList&);
    ShoppingList& operator=(const ShoppingList&);
    ~ShoppingList();

    void addItem(const ShoppingItem& item);
    double totalPrice() const;
    const ShoppingItem* mostExpensive() const;
};

#endif