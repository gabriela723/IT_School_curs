#include "magazin.h"
#include <iostream>
#include <iomanip>

using namespace std;

Magazin::Magazin(Depozit& depozit) : depozit(depozit) {
    produse = {
        {"cartofi", 5.0, 10}, {"mere", 4.5, 15}, {"paine", 3.0, 20},
        {"lapte", 6.0, 12}, {"oua", 10.0, 30}, {"ulei", 9.0, 8},
        {"faina", 7.5, 10}, {"zahar", 8.0, 10}, {"cafea", 15.0, 5},
        {"ciocolata", 12.0, 7}, {"biscuiti", 6.0, 10}, {"ceai", 4.0, 6},
        {"bere", 7.0, 15}, {"vin", 30.0, 8}, {"apa", 2.5, 25},
        {"carne de pui", 20.0, 10}, {"carne de vita", 35.0, 5},
        {"peste", 25.0, 7}, {"branza", 18.0, 9}, {"iaurt", 5.5, 14}
    };
}

void Magazin::display() const {
    cout << "\n=== Produse disponibile in magazin ===\n";
    for (const auto& product : produse) {
        product.display();
    }
}

void Magazin::buyProduct(const string& productName, int cantitate, double cash) {
    for (auto& product : produse) {
        if (product.getNume() == productName) {
            if (product < cantitate) {
                cout << "Stoc insuficient in magazin pentru " << productName << ". Se încearca aducerea din depozit...\n";

                if (!depozit.dinDepozit(productName, cantitate - product.getStoc(), product)) {
                    cout << "Nu s-a putut aduce suficient " << productName << ".\n";
                    return;
                }
            }

            if (product.sell(cantitate)) {
                double total = cantitate * product.getPret();
                if (cash >= total) {
                    cout << "Achizitie reusita: " << cantitate << " x " << productName << " = " << fixed << setprecision(2) << total << " RON\n";
                    cout << "Rest: " << cash - total << " RON\n";
                }
                else {
                    cout << "Fonduri insuficiente! Ai nevoie de "  << total << " RON.\n";
                    product.restock(cantitate); // Anulare vânzare
                }
            }
            else {
                cout << "Nu se poate efectua vanzarea!\n";
            }
            return;
        }
    }
    cout << "Produs inexistent!\n";
}

