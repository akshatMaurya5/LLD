#ifndef COFFEE_VENDING_MACHINE_HPP
#define COFFEE_VENDING_MACHINE_HPP

#include <vector>
#include "coffee.hpp"
#include "inventory.hpp"

using namespace std;

class CoffeeVendingMachine
{

private:
    vector<Coffee> coffeeMenu;
    Inventory inventory;
    double moneyCollected;

public:
    CoffeeVendingMachine();

    void initializeMenu();
    void displayMenu() const;
    bool selectCoffee(CoffeeType type, double payment);
    void refillInventory(CoffeeType type, int quantity);
    double getMoneyCollected() const;
    void displayInventory() const;

private:
    Coffee *findCoffee(CoffeeType type);
};
#endif
