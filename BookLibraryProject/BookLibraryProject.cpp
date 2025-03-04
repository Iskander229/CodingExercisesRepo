// a programm to manage a library system with adding books, searching for them and displaying all the books in the array.
//Used Encapsulation,Templates, Classes, Abstraction, Dynamic memory allocation, user interaction

#include <iostream>
#include <string>
using namespace std;

//Book class
class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor
    Book(const string& t, const string& a, int y) 
        : title(t), author(a), year(y) {}

    //Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    //Setters
    void setTitle(const string& t) { title = t; } //using const string& as additional safety (args cannot be modified)
    void setAuthor(const string& a) { author = a; }
    void setYear(int y) { year = y; }

    //show info
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

// Template Library class
template <typename T>
class Library {
private:
    T** books; // Dynamically store array of any books
    int capacity; // Maximum capacity of the library
    int count; // Current number of books in the library

public:
    // Constructor
    Library() : capacity(10), count(0) {
        books = new T * [capacity]; // Allocate memory for the array
    }

    //cleanup
    ~Library() {
        for (int i = 0; i < count; ++i) {
            delete books[i]; // delete each object
        }
        delete[] books;
    }

    //adding a book
    void addBook(T* book) {
        if (count >= capacity) {
            //resize the array if necessary
            capacity *= 2;
            T** newBooks = new T * [capacity];

            for (int i = 0; i < count; ++i) {
                newBooks[i] = books[i];
            }
            delete[] books;
            books = newBooks;
        }
        books[count++] = book; // Add to the array and count
    }

    //searching for a book
    void searchBook(const string& title) const {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (books[i]->getTitle() == title) {
                books[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No book found with the title: " << title << endl;
        }
    }

    //show all books
    void displayAllBooks() const {
        if (count == 0) {
            cout << "No books in the library." << endl;
        }
        else {
            for (int i = 0; i < count; ++i) {
                books[i]->display();
            }
        }
    }
};


int main() {
    Library<Book> library;
    int choice;
    string title, author;
    int year;

    while (true) {
        cout << "1. Add a book" << endl;
        cout << "2. Search for a book by title" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clearing the buffer

        switch (choice) {
        case 1: {
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter publication year: ";
            cin >> year;
            cin.ignore(); // Clear the input buffer

            Book* newBook = new Book(title, author, year);
            library.addBook(newBook);
            cout << "Book added successfully!" << endl;
            break;
        }
        case 2: {
            cout << "Enter the title to search: ";
            getline(cin, title);
            library.searchBook(title);
            break;
        }
        case 3: {
            library.displayAllBooks();
            break;
        }
        case 4: {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default: {
            cout << "Invalid option. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}
