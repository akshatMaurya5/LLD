#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    int productId;
    int availableStock;
    int lockedStock;

    Product() {}

    Product(int id, int quantity)
    {
        this->productId = id;
        this->availableStock = quantity;
        lockedStock = 0;
    }
};

class Order
{
public:
    int orderId;
    map<int, int> cart; // productId -> quantity
    // bool isConfirmed;

    Order() {}

    Order(int id, map<int, int> products)
    {
        this->orderId = id;
        this->cart = products;
    }

    int getOrderId() const
    {
        return orderId;
    }
};

class Inventory
{
private:
    map<int, Product> stock;
    bool isLocked = false;

public:
    Inventory() {}

    void addProduct(int productId, int quantity)
    {
        if (!stock.count(productId))
        {
            stock[productId] = Product(productId, quantity);
        }
        else
        {
            stock[productId].availableStock += quantity;
        }
    }

    bool createOrder(const Order &order)
    {
        if (isLocked)
        {
            cout << "Inventory is locked right now...." << endl;
            return false;
        }

        isLocked = true;

        // run this for all items before
        for (auto &item : order.cart)
        {
            int productId = item.first;
            int qty = item.second;

            if (!stock.count(productId) || stock[productId].availableStock < qty)
            {
                cout << "Product not available\n";
                isLocked = false;
                return false;
            }
        }

        // now start locking the items

        for (auto &item : order.cart)
        {
            int productId = item.first;
            int qty = item.second;

            stock[productId].availableStock -= qty;
            stock[productId].lockedStock += qty;
        }

        isLocked = false;
        return true;
    }

    bool confirmOrder(Order &order)
    {

        if (isLocked)
            return false;
        isLocked = true;

        for (auto item : order.cart)
        {
            int productId = item.first;
            int qty = item.second;

            if (!stock.count(productId) || stock[productId].lockedStock < qty)
            {
                isLocked = false;
                return false;
            }
        }

        // now confirm all the orders

        for (auto &item : order.cart)
        {

            int productId = item.first;
            int qty = item.second;

            stock[productId].lockedStock -= qty;
        }

        isLocked = false;
        return true;
    }

    int getStock(int productId)
    {
        return stock.count(productId) ? stock[productId].availableStock : 0;
    }
};

class OrderManager
{
private:
    Inventory inventory;
    map<int, Order> orders;
    int nextOrderId = 1;

public:
    void addProduct(int productId, int quantity)
    {
        inventory.addProduct(productId, quantity);
    }

    bool createOrder(map<int, int> toOrder)
    {
        Order newOrder = Order(nextOrderId++, toOrder);

        if (inventory.createOrder(newOrder))
        {
            orders[newOrder.getOrderId()] = newOrder;
            return true;
        }
        return false;
    }

    bool confirmOrder(int orderId)
    {
        if (!orders.count(orderId))
            return false;
        return inventory.confirmOrder(orders[orderId]);
    }

    int getStock(int productId)
    {
        return inventory.getStock(productId);
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("error.txt", "w", stderr);
    //     freopen("output.txt", "w", stdout);
    // #endif

    OrderManager oms;

    // Adding products
    oms.addProduct(101, 50);
    oms.addProduct(102, 30);

    // Create an order
    map<int, int> order1 = {{101, 10}, {102, 5}};

    // FIX: Removed extra parameter (1)
    if (oms.createOrder(order1))
    {
        cout << "Order 1 created successfully!\n";
    }
    else
    {
        cout << "Order 1 creation failed!\n";
    }

    // Get stock after order creation
    cout << "Stock for 101: " << oms.getStock(101) << "\n"; // Should be 40
    cout << "Stock for 102: " << oms.getStock(102) << "\n"; // Should be 25

    // Confirm order
    if (oms.confirmOrder(1))
    {
        cout << "Order 1 confirmed successfully!\n";
    }
    else
    {
        cout << "Order 1 confirmation failed!\n";
    }

    // Get stock after order confirmation
    cout << "Stock for 101 after confirmation: " << oms.getStock(101) << "\n"; // Should still be 40
    cout << "Stock for 102 after confirmation: " << oms.getStock(102) << "\n"; // Should still be 25

    return 0;
}