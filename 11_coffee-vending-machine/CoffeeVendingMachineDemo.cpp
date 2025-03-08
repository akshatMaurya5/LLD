#include "CoffeeVendingMachine.hpp"
#include <iostream>
using namespace std;

int main()
{
    CoffeeVendingMachine machine;

    // Refill inventory
    machine.refillInventory(CoffeeType::ESPRESSO, 5);
    machine.refillInventory(CoffeeType::LATTE, 5);
    machine.refillInventory(CoffeeType::CAPPUCCINO, 5);
    machine.refillInventory(CoffeeType::AMERICANO, 5);

    // Display menu and inventory
    machine.displayMenu();
    machine.displayInventory();

    // Make some purchases
    cout << "\nMaking purchases:" << endl;

    if (machine.selectCoffee(CoffeeType::ESPRESSO, 3.00))
    {
        cout << "Espresso purchased successfully!" << endl;
    }

    if (machine.selectCoffee(CoffeeType::LATTE, 3.50))
    {
        cout << "Latte purchased successfully!" << endl;
    }

    // Try insufficient payment
    if (!machine.selectCoffee(CoffeeType::CAPPUCCINO, 2.00))
    {
        cout << "Cappuccino purchase failed - insufficient payment" << endl;
    }

    // Display updated inventory and money collected
    machine.displayInventory();
    cout << "\nTotal money collected: $" << machine.getMoneyCollected() << endl;

    return 0;
}