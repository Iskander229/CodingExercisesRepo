#include <iostream>
using namespace std;

int main() {
    int* p;
    if (true)
    {
        int a = 5;
        p = &a;
    }
    std::cout <<"it really compiled this:"<< * p;
}