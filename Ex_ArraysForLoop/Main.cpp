#include <iostream>
#include <iterator> // for std::begin() and std::end()


class MyArray {
private:
    int data[5] = { 10, 20, 30, 40, 50 }; // Fixed-size array

public:
    int* begin() { return std::begin(data); }
    int* end() { return std::end(data); }
};

int main() {
    MyArray classInstance;

    // Using for loop with pointers
    for (int* pointer = classInstance.begin(); pointer != classInstance.end(); ++pointer) { //works like do while (until)
        std::cout << *pointer << " ";
    }

    return 0;
}