#include "function.h"
#include <iostream>
using namespace std;

const int MAX_DAYS = 14;   // Overdue threshold
const int FINE_PER_DAY = 100; // Example fine per day

void addBook(LibraryBook books[], int &count) {
    int id; string title, author;
    cout << "Enter Book ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Title: "; getline(cin, title);
    cout << "Enter Author: "; getline(cin, author);
    books[count] = LibraryBook(id, title, author);
    count++;
    cout << "Book added successfully!\n";
}

void displayBooks(LibraryBook books[], int count) {
    for(int i=0; i<count; i++) {
        books[i].displayBook();
    }
}

void searchBook(LibraryBook books[], int count) {
    int id; cout << "Enter Book ID: "; cin >> id;
    for(int i=0; i<count; i++) {
        if(books[i].getBookID() == id) {
            books[i].displayBook();
            return;
        }
    }
    cout << "Book not found.\n";
}

void borrowBookMenu(LibraryBook books[], int count) {
    int id; cout << "Enter Book ID to borrow: "; cin >> id;
    for(int i=0; i<count; i++) {
        if(books[i].getBookID() == id && !books[i].getBorrowStatus()) {
            string name; int days;
            cin.ignore();
            cout << "Enter Borrower Name: "; getline(cin, name);
            cout << "Enter Days Borrowed: "; cin >> days;
            books[i].setBorrowerName(name);
            books[i].setDaysBorrowed(days);
            books[i].setBorrowStatus(true);
            cout << "Book borrowed successfully!\n";
            return;
        }
    }
    cout << "Book not available.\n";
}

void returnBookMenu(LibraryBook books[], int count) {
    int id; cout << "Enter Book ID to return: "; cin >> id;
    for(int i=0; i<count; i++) {
        if(books[i].getBookID() == id && books[i].getBorrowStatus()) {
            books[i].setBorrowerName("");
            books[i].setDaysBorrowed(0);
            books[i].setBorrowStatus(false);
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found or not borrowed.\n";
}

void displayOverdueBooks(LibraryBook books[], int count) {
    for(int i=0; i<count; i++) {
        if(books[i].getBorrowStatus() && books[i].getDaysBorrowed() > MAX_DAYS) {
            books[i].displayBook();
        }
    }
}

void calculateTotalFines(LibraryBook books[], int count) {
    int totalFine = 0;
    for(int i=0; i<count; i++) {
        if(books[i].getBorrowStatus() && books[i].getDaysBorrowed() > MAX_DAYS) {
            totalFine += (books[i].getDaysBorrowed() - MAX_DAYS) * FINE_PER_DAY;
        }
    }
    cout << "Total Fines: " << totalFine << " RWF\n";
}