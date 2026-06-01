#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool isBorrowed;

public:
    // Constructors & Destructor
    LibraryBook();
    LibraryBook(int id, string t, string a);
    ~LibraryBook();

    // Getters & Setters
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getBorrowStatus() const;

    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setBorrowStatus(bool status);

    // Methods
    void displayBook() const;
};

#endif