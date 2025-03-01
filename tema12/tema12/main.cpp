#include <iostream>
#include "product_list.h"

int main() {
    ProductList productList;

    productList.addProduct("faina",5.00 , 5);
    productList.addProduct("ulei", 7.99, 10);
    productList.addProduct("zahar", 6.99, 20);
    productList.addProduct("nutella", 24.99, 20);

    cout << "Lista de produse initiala:" << endl;
    productList.displayProducts();

    ProductList* copiedList = productList.copyList();
    cout << "\nLista copiata:" << endl;
    copiedList->displayProducts();
    delete copiedList;

    productList.deleteProduct("ulei");
    cout << "\nLista dupa stergerea produsului 'ulei':" << endl;
    productList.displayProducts();

    bool res = productList.searchProduct("nutella");
    if (res == true) {
        cout << "\nProdusul 'nutella' este in magazin." << endl;
    }
    else {
        cout << "\nProdusul 'nutella' nu este in magazin." << endl;
    }

    productList.updateQuantity("nutella", 8);
    cout << "\nLista dupa update:" << endl;
    productList.displayProducts();

    productList.sortByPrice();
    cout << "\nLista sortata dupa pret:" << endl;
    productList.displayProducts();

    
    productList.sortByName();
    cout << "\nLista sortata dupa nume:" << endl;
    productList.displayProducts();

    return 0;
}
