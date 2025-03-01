#include <string>
using namespace std;


class Product {
public:
    string name;
    double price;
    int quantity;
    Product* next;

    Product(string n, double p, int q) : name(n), price(p), quantity(q), next(nullptr) {}
};