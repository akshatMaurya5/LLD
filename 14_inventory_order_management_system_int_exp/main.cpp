#include "order-manager.cpp"

int main()
{
    Inventory inventory;
    OrderManager orderManager(&inventory);

    inventory.addProduct(1, 10);
    inventory.addProduct(2, 5);

    map<int, int> orderItems = {{1, 3}, {2, 2}};
    map<int, int> orderItemsMap(orderItems.begin(), orderItems.end());
    if (orderManager.createOrder(1001, orderItems))
    {
        std::cout << "Order 1001 created.\n";
    }

    inventory.getStock(1);
    inventory.getStock(2);

    if (orderManager.confirmOrder(1001))
    {
        std::cout << "Order 1001 confirmed.\n";
    }

    return 0;
}
