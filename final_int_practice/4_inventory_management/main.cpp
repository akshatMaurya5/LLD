#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    int productId;
    int availableStock;
    int blockedStock;

    Product(int id, int qty)
    {
        this->productId = id;
        this->availableStock = qty;
        this->blockedStock = 0;
    }
};

class Inventory
{
public:
    map<int, Product *> products;
    bool isLocked = false;

    void addItem(int prodId, int quantity)
    {
        if (products.count(prodId))
        {
            products[prodId]->availableStock += quantity;
        }
        else
        {
            products[prodId] = new Product(prodId, quantity);
        }
    }

    void blockStock(int prodId, int quantity)
    {
        if (!products.count(prodId))
        {
            cout << "Product not found\n";
            return;
        }
        Product *product = products[prodId];
        if (product->availableStock < quantity)
        {
            cout << "Out of stock\n";
            return;
        }
        product->availableStock -= quantity;
        product->blockedStock += quantity;
    }

    void unblockStock(int prodId, int quantity)
    {
        if (!products.count(prodId) || products[prodId]->blockedStock < quantity)
        {
            cout << "Insufficient blocked stock to unblock\n";
            return;
        }
        products[prodId]->blockedStock -= quantity;
        products[prodId]->availableStock += quantity;
    }

    bool confirmStock(int prodId, int qty)
    {
        if (!products.count(prodId) || products[prodId]->blockedStock < qty)
        {
            cout << "Insufficient blocked stock to confirm\n";
            return false;
        }
        products[prodId]->blockedStock -= qty;
        return true;
    }

    int getStock(int prodId)
    {
        return products.count(prodId) ? products[prodId]->availableStock : 0;
    }

    bool canOrder(int prodId, int quantity)
    {
        return products.count(prodId) && products[prodId]->availableStock >= quantity;
    }

    void lockInventory() { isLocked = true; }
    void unlockInventory() { isLocked = false; }
    bool isInventoryLocked() const { return isLocked; }
};

class Order
{
private:
    int orderId;
    map<int, int> cart;

public:
    Order(int id) : orderId(id) {}
    int getOrderId() const { return orderId; }
    void addProduct(int prodId, int quantity) { cart[prodId] += quantity; }
    map<int, int> getCart() { return cart; }
};

class OrderManager
{
private:
    Inventory inventory;
    map<int, Order *> orders;
    int nextOrderId = 1;

public:
    void addProduct(int prodId, int count) { inventory.addItem(prodId, count); }

    void createOrder(vector<pair<int, int>> &orderedProducts)
    {
        if (inventory.isInventoryLocked())
        {
            cout << "Inventory is locked\n";
            return;
        }

        Order *order = new Order(nextOrderId++);

        for (auto item : orderedProducts)
        {
            if (!inventory.canOrder(item.first, item.second))
            {
                cout << "Item out of stock\n";
                delete order;
                return;
            }
        }

        inventory.lockInventory();

        for (auto item : orderedProducts)
        {
            inventory.blockStock(item.first, item.second);
            order->addProduct(item.first, item.second);
        }

        orders[order->getOrderId()] = order;
        inventory.unlockInventory();
    }

    void confirmOrder(int orderId)
    {
        if (!orders.count(orderId))
        {
            cout << "Order not found\n";
            return;
        }
        inventory.lockInventory();
        Order *order = orders[orderId];
        for (auto &item : order->getCart())
        {
            if (!inventory.confirmStock(item.first, item.second))
            {
                cout << "Insufficient blocked stock to confirm\n";
                inventory.unlockInventory();
                return;
            }
        }
        inventory.unlockInventory();
    }

    int getStock(int productId) { return inventory.getStock(productId); }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    OrderManager orderManager;
    orderManager.addProduct(1, 100);
    orderManager.addProduct(2, 50);

    vector<pair<int, int>> products = {{1, 10}, {2, 5}};
    orderManager.createOrder(products);

    cout << "Stock of product 1: " << orderManager.getStock(1) << endl;
    cout << "Stock of product 2: " << orderManager.getStock(2) << endl;

    orderManager.confirmOrder(1);

    cout << "Stock of product 1: " << orderManager.getStock(1) << endl;
    cout << "Stock of product 2: " << orderManager.getStock(2) << endl;

    return 0;
}
