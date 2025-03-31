#ifndef LIST_LIST_H_
#define LIST_LIST_H_

template<typename T>
class List {
public:
    // Empty the list
    virtual ~List() {}

    // Inserts an element at the start of the list
    virtual void insertAtStart(const T& value) = 0;

    // Inserts an element at the end of the list
    virtual void insertAtEnd(const T& value) = 0;

    // Inserts an element at the index list
    virtual void insertAt(const T& value, const int index) = 0;

    // Removes an element by value
    virtual void remove(const T& value) = 0;

    // Removes an element by index
    virtual void removeAt(const int index) = 0;

    // Return a value at index
    virtual T& getAt(const int index) = 0;

    // return the first element
    virtual T& getFirst() = 0;

    // return the last element
    virtual T& getLast() = 0;

    // Checks if the list is empty
    virtual bool isEmpty() const = 0;

    // Gets the size of the list
    virtual int size() const = 0;

    // Prints the list elements
    virtual void print() const = 0;
};
#endif
