#include "Header.h"

// filled constructor
Account::Account(int accountId, const std::string& accountName)
    : id(accountId), name(accountName) {
    money = new int(0); // allocate money on heap and init to 0
}

//filled destructor
Account::~Account() {
    std::cout << "destructor called\n"; //debug to see when destructor is called
    delete money; // freeing memory allocated for money
}

// modify money
void Account::ModMoney(int amount) {
    *money += amount; 
}

// displaying acc details
void Account::display() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nMoney: " << *money << std::endl;
}
