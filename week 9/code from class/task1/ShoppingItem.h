#ifndef __SHOPPINGITEM_H
#define __SHOPPINGITEM_H

#include <iostream>

class ShoppingItem
{
private:

    char mName[125];
    size_t mCount;
    double mPrice;

    // ShoppingItem **items;

    // items = new ShoppingItem();
    // items = new ShoppingItem[50];
public:
    ShoppingItem(const char*, const size_t, const double);
    ShoppingItem(const ShoppingItem&) = default;

    void setName(const char*);
    void setCount(const size_t);
    void setPrice(const double);

    const char* getName() const;
    size_t getCount() const;
    double getPrice() const;

    double calculateTotal() const;
};

#endif