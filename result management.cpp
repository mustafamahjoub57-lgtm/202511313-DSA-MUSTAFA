#include <iostream>
#include <string>
using namespace std;

// Function to display results based on average marks
void displayResults(double average) {
   if (average >= 50) {
    cout << "Passed! " << endl;
   } else {
    cout << "Failed! " << endl;
   }
}

int main() {

    // Declaring variables
    string Studentname;
    int marks[3];
    double average;
    double total;
    string choice;


    // Loop to input multiple students' names and marks
    do {
        // Input student's name
        cout << "Enter Student's name: ";
        cin >> Studentname;

       // Input marks for 3 subjects
        cout << "Enter marks for 3 subjects: " << endl;
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
        
        // Calculate total and average
        total = marks[0] + marks[1] + marks[2];
        average = total / 3.0;

        cout << "Total marks for " << Studentname << " = " << total << endl;
        cout << "Average marks for " << Studentname << " = " << average << "%" << endl;

        // Display the results
        displayResults(average);

        cout << "-----------------------------" << endl;

        cout << "Do you want to enter another student's name? (yes/no): ";
        cin >> choice;
        cout << endl;

    } while (choice == "yes" || choice == "Yes");

    return 0;
}