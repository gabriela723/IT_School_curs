#include "Produs.h"

using namespace std;

Produs::Produs(const std::string& nume, double pret, int stoc)
    : nume(nume), pret(pret), stoc(stoc) {}

Produs::Produs(const Produs& other)
    : nume(other.nume), pret(other.pret), stoc(other.stoc) {}

Produs::Produs(Produs&& other) noexcept
    : nume(std::move(other.nume)), pret(other.pret), stoc(other.stoc) {
    other.stoc = 0;
}

Produs& Produs::operator=(const Produs& other) {
    if (this != &other) {
        nume = other.nume;
        pret = other.pret;
        stoc = other.stoc;
    }
    return *this;
}

Produs& Produs::operator=(Produs&& other) {
    if (this != &other) {
        nume = std::move(other.nume);
        pret = other.pret;
        stoc = other.stoc;
        other.stoc = 0;
    }
    return *this;
}

bool Produs::operator<(int cantitate) const {
    return stoc < cantitate;
}

void Produs::restock(int cantitate) {
    stoc += cantitate;
    cout << "Produsul " << nume << " a fost adus din depozit (+"
        << cantitate << "). Stoc actual: " << stoc << "\n";
}

bool Produs::sell(int cantitate) {
    if (stoc >= cantitate) {
        stoc -= cantitate;
        return true;
    }
    return false;
}

double Produs::getPret() const {
    return pret;
}

std::string Produs::getNume() const {
    return nume;
}

int Produs::getStoc() const {
    return stoc;
}

void Produs::display() const {
   cout << nume << " - " << pret << " RON (Stoc: " << stoc << ")\n";
}
