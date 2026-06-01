#include "function.h"
#include <iostream>
using namespace std;

struct LibraryBook {};

void addBook(LibraryBook books[], int &count);
void displayBooks(LibraryBook books[], int count);
void borrowBookMenu(LibraryBook books[], int count);
void returnBookMenu(LibraryBook books[], int count);
void searchBook(LibraryBook books[], int count);
void displayOverdueBooks(LibraryBook books[], int count);
void calculateTotalFines(LibraryBook books[], int count);

int main() {
    LibraryBook books[100];
    int count = 0;
    int choice;

    do {
        cout << "\n===== LIBRARY BOOK BORROWING SYSTEM =====\n";
        cout << "1. Add New Book\n2. Display All Books\n3. Borrow Book\n4. Return Book\n";
        cout << "5. Search Book by ID\n6. Display Overdue Books\n7. Calculate Total Fines\n8. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1: addBook(books, count); break;
            case 2: displayBooks(books, count); break;
            case 3: borrowBookMenu(books, count); break;
            case 4: returnBookMenu(books, count); break;
            case 5: searchBook(books, count); break;
            case 6: displayOverdueBooks(books, count); break;
            case 7: calculateTotalFines(books, count); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 8);

    return 0;
}