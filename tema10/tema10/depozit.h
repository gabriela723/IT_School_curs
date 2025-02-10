#pragma once
#include "Produs.h"
#include <vector>

class Depozit {
private:
    std::vector<Produs> stock;

public:
    Depozit();
    void display() const;
    bool dinDepozit(const std::string& productName, int quantity, Produs& storeProduct);
};

