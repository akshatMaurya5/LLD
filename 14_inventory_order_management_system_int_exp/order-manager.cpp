#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "order.cpp"
#include "inventory.cpp"
#include <map>
using namespace std;

class OrderManager
{
private:
    map<int, Order *> orders;
    Inventory *inventory;

public:
    OrderManager()
    {
        orders = map<int, Order *>();
    }

    OrderManager(Inventory *inventory)
    {
        this->inventory = inventory;
    }

    bool createOrder(int orderId, map<int, int> productQuantities)
    {
        // First verify if we can block all products
        for (auto product : productQuantities)
        {
            int productId = product.first;
            int quantity = product.second;

            if (!inventory->blockStock(productId, quantity))
            {
                // If any product can't be blocked, release all previously blocked products
                for (auto prevProduct = productQuantities.begin(); prevProduct->first != productId; ++prevProduct)
                {
                    inventory->releaseStock(prevProduct->first, prevProduct->second);
                }
                cout << "Failed to block stock for product " << productId << endl;
                return false;
            }
        }

        // Create new order and add products
        Order *newOrder = new Order(orderId, productQuantities);
        orders[orderId] = newOrder;
        return true;
    }

    bool confirmOrder(int orderId)
    {
        if (orders.find(orderId) == orders.end() || orders[orderId]->status != OrderStatus::PENDING)
        {
            return false;
        }

        for (auto &product : orders[orderId]->products)
        {
            auto productId = product.first;
            auto quantity = product.second;
            inventory->confirmStock(productId, quantity);
        }
        orders[orderId]->status = OrderStatus::CONFIRMED;
        return true;
    }

    void cancelOrder(int orderId)
    {
        if (orders.find(orderId) == orders.end() || orders[orderId]->status != OrderStatus::PENDING)
        {
            return;
        }

        auto order = orders[orderId];

        auto productsOrdered = order->products;

        for (auto product : productsOrdered)
        {
            auto productId = product.first;
            auto quantity = product.second;
            inventory->releaseStock(productId, quantity);
        }

        orders.erase(orderId);
        delete order;
    }
};
#endif