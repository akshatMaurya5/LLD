#include "inventory.hpp"
#include <iostream>
using namespace std;
Inventory::Inventory()
{
    items[CoffeeType::ESPRESSO] = 0;
    items[CoffeeType::LATTE] = 0;
    items[CoffeeType::CAPPUCCINO] = 0;
    items[CoffeeType::AMERICANO] = 0;
}

void Inventory::addItem(CoffeeType type, int quantity)
{
    items[type] += quantity;
}

bool Inventory::hasItem(CoffeeType type)
{
    return items[type] > 0;
}

void Inventory::deductItem(CoffeeType type)
{
    if (items[type] > 0)
    {
        items[type]--;
    }
}

int Inventory::getQuantity(CoffeeType type) const
{
    auto it = items.find(type);
    return it != items.end() ? it->second : 0;
}

void Inventory::display() const
{
    cout << "\nCurrent Inventory:" << endl;
    cout << "Espresso: " << items.at(CoffeeType::ESPRESSO) << endl;
    cout << "Latte: " << items.at(CoffeeType::LATTE) << endl;
    cout << "Cappuccino: " << items.at(CoffeeType::CAPPUCCINO) << endl;
    cout << "Americano: " << items.at(CoffeeType::AMERICANO) << endl;
}
