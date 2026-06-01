#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice, subChoice;
    string line;

    do {
        cout << "\t\t\t=== Foundations and History of C++ ===" << endl;
        cout << "\t\t\t1. View History of C++" << endl;
        cout << "\t\t\t2. Learn about C++ Concepts" << endl;
        cout << "\t\t\t3. Exit" << endl;
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\t\t\t--- History of C++ ---" << endl;
            cout << "\t\t\t1. Origin of C++" << endl;
            cout << "\t\t\t2. Development of C++" << endl;
            cout << "\t\t\t3. Evolution of C++" << endl;
            cout << "\t\t\tEnter chapter number: ";
            cin >> subChoice;

            if (subChoice == 1) {
                cout << "\t\t\tOrigin of C++:" << endl;
                cout << "\t\t\tC++ was developed by Bjarne Stroustrup in 1979 at Bell Labs..." << endl;
            } else if (subChoice == 2) {
                cout << "\t\t\tDevelopment of C++:" << endl;
                cout << "\t\t\tC++ evolved from C with classes, adding object-oriented features..." << endl;
            } else if (subChoice == 3) {
                cout << "\t\t\tEvolution of C++:" << endl;
                cout << "\t\t\tC++ has undergone multiple standard revisions: C++98, C++11, C++17, C++20..." << endl;
            } else {
                cout << "\t\t\tInvalid chapter." << endl;
            }
            break;

        case 2:
            cout << "\t\t\t--- Learn about C++ Concepts ---" << endl;
            cout << "\t\t\t1. Data Types" << endl;
            cout << "\t\t\t2. Control Flow" << endl;
            cout << "\t\t\t3. Loops" << endl;
            cout << "\t\t\t4. Arrays" << endl;
            cout << "\t\t\t5. File Streams" << endl;
            cout << "\t\t\tEnter chapter number: ";
            cin >> subChoice;

            if (subChoice == 1) {
                cout << "\t\t\tData Types:" << endl;
                cout << "\t\t\tC++ supports int, float, double, char, bool, etc." << endl;
            } else if (subChoice == 2) {
                cout << "\t\t\tControl Flow:" << endl;
                cout << "\t\t\tIncludes if-else, switch-case, and conditional operators." << endl;
            } else if (subChoice == 3) {
                cout << "\t\t\tLoops:" << endl;
                cout << "\t\t\tFor, while, and do-while loops are used for iteration." << endl;
            } else if (subChoice == 4) {
                cout << "\t\t\tArrays:" << endl;
                cout << "\t\t\tArrays store multiple values of the same type in contiguous memory." << endl;
            } else if (subChoice == 5) {
                cout << "\t\t\tFile Streams:" << endl;
                ifstream file("filestream.txt"); // external file
                if (file.is_open()) {
                    while (getline(file, line)) {
                        cout << line << endl;
                    }
                    file.close();
                } else {
                    cout << "\t\t\tUnable to open filestream.txt. Please create the file." << endl;
                }
            } else {
                cout << "\t\t\tInvalid chapter." << endl;
            }
            break;

        case 3:
            cout << "\t\t\tExiting program. Goodbye!" << endl;
            break;

        default:
            cout << "\t\t\tInvalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}