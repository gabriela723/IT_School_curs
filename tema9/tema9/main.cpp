#include <iostream>
 
using namespace std;


class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
protected:
    double balance;
public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};

Account::Account()
    :Account(0.0) {   //delegarea constructorului

}

Account::Account(double balance)
    :balance(balance) {

}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (balance - amount >= 0)
        balance -= amount;
    else
        std::cout << "Ã¯nsuficient funds" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account balance" << account.balance;
    return os;
}





class Saving_Account : public Account {
    friend std::ostream& operator<<(std::ostream& os, const Saving_Account& account);
protected:
    double int_rate;
public:
    Saving_Account();
    Saving_Account(double balance, double int_rate);
    void deposit(double amount);
};

Saving_Account::Saving_Account(double balance, double int_rate)
    :Account(balance), int_rate(int_rate) {

}

Saving_Account::Saving_Account()
    :Saving_Account(0.0, 0.0) {

}

void Saving_Account::deposit(double amount) {
    amount = amount + (amount * int_rate / 100);
    Account::deposit(amount);
}


std::ostream& operator<<(std::ostream& os, const Saving_Account& account) {
    os << "Saving_account balance" << account.balance << "Interest rate" << account.int_rate;
    return os;
}



int main() {

    std::cout << "\n================Account===============" << std::endl;

    Account a1{ 1000 };
    cout << a1 << endl;

    a1.deposit(1000);
    cout << a1 << endl;

    a1.withdraw(1000);
    cout << a1 << endl;

    std::cout << "\n================Saving_Account===============" << std::endl;

    Saving_Account s1{ 1000.5,5 };
    cout << s1 << endl;

    s1.deposit(1000);
    cout << s1 << endl;

    s1.withdraw(2000);
    cout << s1 << endl;

    s1.withdraw(1000);
    cout << s1 << endl;


    return 0;
}