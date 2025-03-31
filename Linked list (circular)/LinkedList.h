#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include "list.h"
#include "Node.h"


template<typename T>
class LinkedList : public List<T> {
public:
    Node<T>* head;
    int listSize;

    LinkedList() : head(nullptr), listSize(0) {}

    ~LinkedList() {
        if (head == nullptr) return;

        Node<T>* current = head;
        do {
            Node<T>* next = current->next;
            delete current;
            current = next;
        } while (current != head);
    }

    Node<T>* getLastNode() {


        Node<T>* current = head;
        for (int i = 0; i < listSize - 1; i++) {
            current = current->next;
        }
        return current;
    }

    void insertAtStart(const T& value) override {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head;

        }
        else {
            Node<T>* last = getLastNode();
            last->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        listSize++;
    }

    void insertAtEnd(const T& value) override {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node<T>* last = getLastNode();
            last->next = newNode;
            newNode->next = head;
        }
        listSize++;
    }

    void insertAt(const T& value, const int index) override {
        if (index < 0 || index > listSize) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            insertAtStart(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        listSize++;
    }

    void removeHead() {
        if (head == nullptr) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* last = getLastNode();
            last->next = head->next;
            delete head;
            head = last->next;
        }
        listSize--;
    }

    void remove(const T& value) override {
        if (head == nullptr) return;
        if (head->data == value) {
            removeHead();
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        do {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                listSize--;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }

    void removeAt(const int index) override {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            removeHead();
            return;
        }

        Node<T>* current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        listSize--;
    }

    T& getFirst() override {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    T& getLast() override {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return getLastNode()->data;
    }

    T& getAt(const int index) override {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = head;
        for (int i = 0; i <= index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    bool isEmpty() const override {
        return head == nullptr;
    }

    int size() const override {
        return listSize;
    }

    void print() const override {
        if (head != nullptr) {};

        Node<T>* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

#endif
