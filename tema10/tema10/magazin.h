#pragma once
#include "produs.h"
#include "depozit.h"
#include <vector>

using namespace std;

class Magazin {
private:
    vector<Produs> produse;
    Depozit& depozit;

public:
    Magazin(Depozit& depozit);
    void display() const;
    void buyProduct(const std::string& productName, int cantitate, double cash);
};

