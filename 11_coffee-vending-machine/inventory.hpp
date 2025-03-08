#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "coffee-type.hpp"
#include <map>

using namespace std;

class Inventory
{
private:
    map<CoffeeType, int> items;

public:
    Inventory();

    void addItem(CoffeeType type, int quantity);
    bool hasItem(CoffeeType type);
    void deductItem(CoffeeType type);
    int getQuantity(CoffeeType type) const;
    void display() const;
};

#endif
