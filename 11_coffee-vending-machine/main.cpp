#include "CoffeeVendingMachine.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void testBasicOperations(CoffeeVendingMachine &machine)
{
    cout << "\n=== Testing Basic Operations ===" << endl;

    // Initial inventory check
    cout << "\nInitial state:" << endl;
    machine.displayMenu();
    machine.displayInventory();

    // Refill inventory
    cout << "\nRefilling inventory..." << endl;
    machine.refillInventory(CoffeeType::ESPRESSO, 5);
    machine.refillInventory(CoffeeType::LATTE, 3);
    machine.refillInventory(CoffeeType::CAPPUCCINO, 4);
    machine.refillInventory(CoffeeType::AMERICANO, 2);

    machine.displayInventory();
}

void testPurchases(CoffeeVendingMachine &machine)
{
    cout << "\n=== Testing Purchase Scenarios ===" << endl;

    // Successful purchase with exact amount
    cout << "\nTesting purchase with exact amount:" << endl;
    machine.selectCoffee(CoffeeType::ESPRESSO, 2.50);

    // Successful purchase with change
    cout << "\nTesting purchase with change:" << endl;
    machine.selectCoffee(CoffeeType::LATTE, 5.00);

    // Failed purchase - insufficient payment
    cout << "\nTesting insufficient payment:" << endl;
    machine.selectCoffee(CoffeeType::CAPPUCCINO, 1.00);

    cout << "\nInventory after purchases:" << endl;
    machine.displayInventory();

    cout << "\nTotal money collected: $" << fixed << setprecision(2)
         << machine.getMoneyCollected() << endl;
}

void testOutOfStock(CoffeeVendingMachine &machine)
{
    cout << "\n=== Testing Out of Stock Scenario ===" << endl;

    // Buy all remaining Americanos
    cout << "\nBuying all remaining Americano..." << endl;
    machine.selectCoffee(CoffeeType::AMERICANO, 2.00);
    machine.selectCoffee(CoffeeType::AMERICANO, 2.00);

    // Try to buy when out of stock
    cout << "\nTrying to buy out-of-stock Americano:" << endl;
    machine.selectCoffee(CoffeeType::AMERICANO, 2.00);

    machine.displayInventory();
}

int main()
{
    cout << "=== Coffee Vending Machine Test ===" << endl;

    // Create vending machine instance
    CoffeeVendingMachine machine;

    // Run tests
    testBasicOperations(machine);
    testPurchases(machine);
    testOutOfStock(machine);

    cout << "\n=== Final Machine Status ===" << endl;
    machine.displayMenu();
    machine.displayInventory();
    cout << "Total money collected: $" << fixed << setprecision(2)
         << machine.getMoneyCollected() << endl;

    return 0;
}
