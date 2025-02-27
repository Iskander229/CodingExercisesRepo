#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    size_t size;
public:
    Array(size_t Size) 
        : size(Size), data(new int[Size]){} //creating dynamic array new int size

    ~Array() {
        delete[] data;
    }

    int& operator[](size_t index) { //overload operator[]
        return data[index];         //returns address (int&) to change values
    }
    int* begin() {
        return data; //returns pointers to first element
    }
    int* end() {
        return data + size; //returns pointers to last element
    }
};

int main()
{
    size_t Size = 5;
    Array values(Size);

    for (size_t i = 0; i < Size; i++) { //cout to enter user values
        cout << "values: [" << i <<"] =";
        cin >> values[i];
        cout << endl;
    }

    for (int value : values) { //range based for loop (begin & end return pointers
        cout << value << endl;
    }

    return 0;
}

