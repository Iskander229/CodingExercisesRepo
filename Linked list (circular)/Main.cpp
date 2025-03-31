#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    // Test your implementation
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);

    std::cout << "List contents: ";
    list.print();

    std::cout << "First element: " << list.getFirst() << std::endl;
    std::cout << "Last element: " << list.getLast() << std::endl;

    return 0;
}//test