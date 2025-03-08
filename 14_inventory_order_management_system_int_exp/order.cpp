#ifndef ORDER_H
#define ORDER_H

#include "inventory.cpp"

enum OrderStatus
{
    PENDING,
    CONFIRMED
};

class Order
{
public:
    int orderId;
    map<int, int> products;
    OrderStatus status;

    Order()
    {
        products = map<int, int>();
    }

    Order(int id, map<int, int> products)
    {
        this->orderId = id;
        this->products = products;
        this->status = OrderStatus::PENDING;
    }
};
#endif
