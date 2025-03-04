#include <iostream>

//Template function to sum 
template <typename T>
T SumArray(const T* array, int size) {
    T sum = 0; //Init sum

    //Sum iteration
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return sum; 
}

int main() {
    //with different numeric types

    //int array
    int Array[] = { 1, 2, 3, 4, 5 };
    int Size = sizeof(Array) / sizeof(Array[0]);
    std::cout << "Sum of intArray: " << SumArray(Array, Size) << std::endl;

    //float array
    float floatArray[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "Sum of floatArray: " << SumArray(floatArray, floatSize) << std::endl;

    //double array
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Sum of doubleArray: " << SumArray(doubleArray, doubleSize) << std::endl;

    return 0;
}