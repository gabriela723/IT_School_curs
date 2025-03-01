#pragma once

#include <iostream>
#include "product.cpp"
using namespace std;

class ProductList {
private:
    Product* head;

public:
    ProductList();
    ~ProductList();
    void addProduct(string name, double price, int quantity);
    void displayProducts() const;
    ProductList* copyList() ;
    void deleteProduct(string name);
    bool searchProduct(string name);
    void updateQuantity(string name, int newQuantity);
    void sortByPrice();
    void sortByName();
};