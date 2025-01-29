#include <iostream>
using namespace std;

int main() {
    int variable = 42;
    int* ptr = &variable; // Pointer stores the address of variable

    cout << "Address of variable: " << ptr << endl;  // Address stored in ptr
    cout << "Value of variable: " << *ptr << endl;   // Dereference to access value

    // Dynamic memory allocation
    ptr = new int(100); // Allocate memory
    cout << "Dynamically allocated value: " << *ptr << endl;
}