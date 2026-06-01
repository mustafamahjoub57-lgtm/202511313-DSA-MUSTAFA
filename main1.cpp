#include "notepad.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice;
    string filename;
    
    // Display menu repeatedly using a do-while loop
    do {
        
        cout << "===SIMPLE NOTEPAD=== " << endl;
        cout << "1. Write File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Append File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        // Handle invalid numerical menu choices or non-integer inputs safely
        if (cin.fail()) {
            cin.clear(); // clear error flag
            string dummy;
            cin >> dummy; // discard bad input
            choice = 0;   // force default switch case
        }
        
        // Use switch statements for menu choices
        switch (choice) {
            case 1:
                cout << "Enter filename to create/write (e.g., notes.txt): ";
                cin >> filename;
                cin.ignore(); // Clear the input buffer before using getline
                writeFile(filename);
                break;
                
            case 2:
                cout << "Enter filename to read: ";
                cin >> filename;
                cin.ignore();
                readFile(filename);
                break;
                
            case 3:
                cout << "Enter filename to append to: ";
                cin >> filename;
                cin.ignore();
                appendFile(filename);
                break;
                
            case 4:
                cout << "Exiting the program. " << endl;
                break;
                
            default:
                cout << "Invalid choice! Please select a valid option (1-4)." << endl;
                break;
        }
        
    } while (choice != 4); 
    
    return 0;
}