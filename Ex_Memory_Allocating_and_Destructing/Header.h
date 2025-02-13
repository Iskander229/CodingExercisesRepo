#ifndef HEADER_H // trad guards
#define HEADER_H

#include <string>
#include <iostream>

class Account {
private:
    //privatae vars
    int id;
    std::string name;
    int* money;           // Pointer to money on heap

public:
    //constructor, later should allocate money on the heap and init it to 0
    Account(int accountId, const std::string& accountName);

    //destructor to free memory (*money)
    ~Account();

    //func to modify the money value
    void ModMoney(int amount);

    //const function to display accdetails
    void display() const;
};

#endif
