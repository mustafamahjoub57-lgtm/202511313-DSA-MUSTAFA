#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LibraryBook.h"

void addBook(LibraryBook books[], int &count);
void displayBooks(LibraryBook books[], int count);
void searchBook(LibraryBook books[], int count);
void borrowBookMenu(LibraryBook books[], int count);
void returnBookMenu(LibraryBook books[], int count);
void displayOverdueBooks(LibraryBook books[], int count);
void calculateTotalFines(LibraryBook books[], int count);

#endif