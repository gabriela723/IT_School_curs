#include "depozit.h"
#include <iostream>

using namespace std;

Depozit::Depozit() {
    stock = {
        {"cartofi", 5.0, 50}, {"mere", 4.5, 40}, {"paine", 3.0, 60},
        {"lapte", 6.0, 30}, {"oua", 10.0, 100}, {"ulei", 9.0, 40},
        {"faina", 7.5, 50}, {"zahar", 8.0, 50}, {"cafea", 15.0, 20},
        {"ciocolata", 12.0, 30}, {"biscuiti", 6.0, 50}, {"ceai", 4.0, 25},
        {"bere", 7.0, 60}, {"vin", 30.0, 20}, {"apa", 2.5, 80},
        {"carne de pui", 20.0, 40}, {"carne de vita", 35.0, 20},
        {"peste", 25.0, 30}, {"branza", 18.0, 30}, {"iaurt", 5.5, 40}
    };
}

void Depozit::display() const {
    cout << "\n=== Stoc in depozit ===\n";
    for (const auto& product : stock) {
        product.display();
    }
}

bool Depozit::dinDepozit(const string& productName, int quantity, Produs& storeProduct) {
    for (auto& product : stock) {
        if (product.getNume() == productName && product.getStoc() >= quantity) {
            product.sell(quantity);
            storeProduct.restock(quantity);
            return true;
        }
    }
    cout << "Depozitul nu are suficient " << productName << "!\n";
    return false;
}
