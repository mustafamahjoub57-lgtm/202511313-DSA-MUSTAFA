#include "LibraryBook.h"

LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

LibraryBook::~LibraryBook() {
    cout << "Book object with ID " << bookID << " destroyed." << endl;
}

// Getters
int LibraryBook::getBookID() const { return bookID; }
string LibraryBook::getTitle() const { return title; }
string LibraryBook::getAuthor() const { return author; }
string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getBorrowStatus() const { return isBorrowed; }

// Setters
void LibraryBook::setBorrowerName(string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setBorrowStatus(bool status) { isBorrowed = status; }

// Display
void LibraryBook::displayBook() const {
    cout << "ID: " << bookID << " | Title: " << title 
         << " | Author: " << author 
         << " | Borrowed: " << (isBorrowed ? "Yes" : "No");
    if(isBorrowed) {
        cout << " | Borrower: " << borrowerName 
             << " | Days: " << daysBorrowed;
    }
    cout << endl;
}