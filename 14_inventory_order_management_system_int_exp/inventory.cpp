
#ifndef INVENTORY_H
#define INVENTORY_H

#include "product.cpp"
#include <map>
using namespace std;

class Inventory
{
private:
    map<int, Product *> inventory;

public:
    Inventory()
    {
        inventory = map<int, Product *>();
    }

    void addProduct(int productId, int quantity)
    {
        if (inventory.find(productId) == inventory.end())
        {
            inventory[productId] = new Product(productId, quantity);
        }
        else
        {
            inventory[productId]->availableStock += quantity;
        }
    }

    bool blockStock(int productId, int quantity)
    {
        if (inventory.find(productId) == inventory.end() || inventory[productId]->availableStock < quantity)
        {
            return false;
        }
        inventory[productId]->blockedStock += quantity;
        inventory[productId]->availableStock -= quantity;
        return true;
    }

    bool releaseStock(int productId, int quantity)
    {
        if (inventory.find(productId) == inventory.end() || inventory[productId]->blockedStock < quantity)
        {
            return false;
        }
        inventory[productId]->blockedStock -= quantity;
        inventory[productId]->availableStock += quantity;
        return true;
    }

    void confirmStock(int productId, int quantity)
    {
        if (inventory.count(productId))
        {
            inventory[productId]->blockedStock -= quantity;
        }
    }

    int getStock(int productId)
    {
        if (inventory.count(productId))
        {
            return inventory[productId]->availableStock;
        }
        return 0;
    }
};
#endif