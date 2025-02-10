#pragma once
#include <iostream>
#include <string>

class Produs {
private:
    std::string nume;
    double pret;
    int stoc;

public:
    Produs(const std::string& nume, double pret, int stocc);
    Produs(const Produs& other); // Copy Constructor
    Produs(Produs&& other) noexcept; // Move Constructor

    Produs& operator=(const Produs& other); // Copy Assignment
    Produs& operator=(Produs&& other); // Move Assignment

    bool operator<(int cantitate) const; // Overloading pentru comparatie

    void restock(int cantitate); // Adauga produse din depozit
    bool sell(int cantitate); // Vinde produsele si scade din stoc

    double getPret() const;
    std::string getNume() const;
    int getStoc() const;

    void display() const;
};

