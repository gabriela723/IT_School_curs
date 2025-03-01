#include <iostream>
#include "product_list.h"

ProductList::ProductList() : head(nullptr) {}

ProductList::~ProductList() {
    Product* current = head;
    while (current) {
        Product* next = current->next;
        delete current;
        current = next;
    }
}

void ProductList::addProduct(string name, double price, int quantity) {
    Product* newProduct = new Product(name, price, quantity);
    if (!head) {
        head = newProduct;
    }
    else {
        Product* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
}

void ProductList::displayProducts() const {
    Product* temp = head;
    while (temp) {
        cout << "Name: " << temp->name << ", Price: " << temp->price << ", Quantity: " << temp->quantity << endl;
        temp = temp->next;
    }
}

ProductList* ProductList::copyList()  {
    if (!head) return new ProductList();
    ProductList* newList = new ProductList();
    Product* temp = head;
    while (temp) {
        newList->addProduct(temp->name, temp->price, temp->quantity);
        temp = temp->next;
    }
    return newList;
}

void ProductList::deleteProduct(string name) {
    if (!head) return;
    if (head->name == name) {
        Product* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Product* current = head;
    while (current->next && current->next->name != name) {
        current = current->next;
    }
    if (current->next) {
        Product* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

bool ProductList::searchProduct(string name) {
    if (!head) exit;
    if (head->name == name) {
        return true;
    }
    Product* current = head;
    while (current->next && current->next->name != name) {
        current = current->next;
    }
    if (current->next) {
        return true;
    }
    return false;
}

void ProductList::updateQuantity(string name, int newQuantity) {
    Product* temp = head;
    while (temp) {
        if (temp->name == name) {
            temp->quantity = newQuantity;
            return;
        }
        temp = temp->next;
    }
}

void ProductList::sortByPrice() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Product* current = head;
        while (current->next) {
            if (current->price > current->next->price) {
                swap(current->name, current->next->name);
                swap(current->price, current->next->price);
                swap(current->quantity, current->next->quantity);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void ProductList::sortByName() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Product* current = head;
        while (current->next) {
            if (current->name > current->next->name) {
                swap(current->name, current->next->name);
                swap(current->price, current->next->price);
                swap(current->quantity, current->next->quantity);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}


