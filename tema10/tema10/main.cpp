#include <iostream>
#include "magazin.h"
#include "depozit.h"

using namespace std;


/*
Mandatory:Sa sa implementeze o aplicatie in care sa avem un magazin cu aproximativ 20 de produse deja stabilite de voi 
si o anumita cantinate(ex. 10 saci de cartofi), daca clientul cere 11 sa se aduca produsul din depozit 
(aici o sa folositi overloading pentru comparare opy/move constructor pentru a aduce produsele din depozit).

Extra puteti sa stabiliti pretul produselor si sa calculati cat are de platit clientul, suma ce o primiti si cat trebuie sa oferiti rest.
*/

int main() {

        Depozit depozit;
        Magazin magazin(depozit);
        int optiune;
        string productName;
        int cantitate;
        double cash;

        while (true) {
            magazin.display();
            cout << "1. Cumpara produs\n" << "2. Vezi stoc depozit\n"  << "0. Iesire\n";
            cout << "Alege optiunea: ";
            cin >> optiune;

            if (optiune == 0) break;

            if (optiune == 2) {
                depozit.display();
                continue;
            }

            cout << "Introdu numele produsului: ";
            cin.ignore();
            getline(cin, productName);

            cout << "Cantitate: ";
            cin >> cantitate;

            cout << "Suma disponibila: ";
            cin >> cash;

            magazin.buyProduct(productName, cantitate, cash);
        }

	return 0;
}