#include "notepad.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to create a new file and write text into it
void writeFile(string filename) {
    ofstream outFile(filename); // Open file in default write mode (overwrites old content)
    
    if (!outFile) {
        cout << "Error: Could not create the file." << endl;
        return;
    }
    
    cout << "--- Writing to " << filename << " ---" << endl;
    cout << "Type your text. To stop and save, type 'END' on a new line." << endl;
    
    string line;
    // Loop to read multiple lines of input from the user
    while (getline(cin, line)) {
        if (line == "END") {
            break; // Stop writing when user enters END
        }
        outFile << line << endl; // Save text into the file
    }
    
    outFile.close(); // Close file properly
    cout << "File saved successfully!" << endl;
}

// Function to read and display all contents of a file
void readFile(string filename) {
    ifstream inFile(filename); // Open file in read mode
    
    // Handle file-not-found situations
    if (!inFile) {
        cout << "Error: File '" << filename << "' does not exist!" << endl;
        return;
    }
    
    cout << "--- Reading Content of " << filename << " ---" << endl;
    string line;
    // Read the file line by line and display it to the console
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    
    inFile.close(); // Close file properly
    cout << "---------------------------------------" << endl;
}

// Function to append new text to the end of an existing file
void appendFile(string filename) {
    ofstream outFile(filename, ios::app); // Open the file in append mode
    
    if (!outFile) {
        cout << "Error: Could not open the file for appending." << endl;
        return;
    }
    
    cout << "--- Appending to " << filename << " ---" << endl;
    cout << "Type your text to add. To stop and save, type 'END' on a new line." << endl;
    
    string line;
    // Loop to get user input until they type END
    while (getline(cin, line)) {
        if (line == "END") {
            break; // Stop appending when user types END
        }
        outFile << line << endl; // Add new text without deleting old content
    }
    
    outFile.close(); // Close file properly
    cout << "Content appended successfully!" << endl;
}