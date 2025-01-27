#include "Header.h"
#include <iostream>
#include <string>

int main() {
    //just creating new account obj
    Account myAccount(1, "John Doe");

    //using display func for showing initial acc details
    std::cout << "Initial Account Details:" << std::endl;
    myAccount.display();

    //modifying money
    myAccount.ModMoney(500);
    std::cout << "\nAfter Adding 500:" << std::endl;
    myAccount.display();

    myAccount.ModMoney(-200);
    std::cout << "\nAfter Subtracting 200:" << std::endl;
    myAccount.display();

    
    return 0;
}
