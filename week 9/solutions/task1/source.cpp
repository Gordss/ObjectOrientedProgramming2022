#include <iostream>
#include "ShoppingList.h"

int main()
{
    ShoppingItem item1("T-Shirt", 1, 16.00);
    ShoppingItem item2("Shorts", 1, 7.00);
    ShoppingItem item3("Socks", 1, 4.00);
    ShoppingItem item4("Sneakers", 1, 120.00);

    ShoppingList list(6);
    list.addItem(item1);
    list.addItem(item2);
    list.addItem(item3);
    list.addItem(item4);

    list.addItem(item1);

    const ShoppingItem* mostExpensive = list.mostExpensive();
    std::cout << "Most expensive item: "
              << mostExpensive->getName() << '\n'
              << "At price: "
              << mostExpensive->getPrice() << '\n';
    
    std::cout << "\n\nBill total: " << list.totalPrice() << '\n';
}