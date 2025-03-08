#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product
{
public:
    int productId;
    int availableStock;
    int blockedStock; // for unconfirmed orders

    Product(int id, int quantity)
    {
        this->productId = id;
        this->availableStock = quantity;
        this->blockedStock = 0;
    }

    void displayStock()
    {
        cout << "Product ID: " << productId << ", Available: " << availableStock << ", Blocked: " << blockedStock << endl;
    }
};
#endif