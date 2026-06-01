#include "student1.h"
#include <iostream>
#include <vector>
#include <student.h>

using namespace std;

int main() {

    std::vector<Student> students;
    int choice;

    do {

        cout << "===STUDENT MANAGEMENT SYSTEM=== " << endl;
        cout << "1. Add a Student " << endl;
        cout << "2. Display All Students " << endl;
        cout << "3. Search for a Student by ID " << endl;
        cout << "4. Update Student Information " << endl;
        cout << "5. Delete a Student " << endl;
        cout << "6. Exit " << endl;

        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                addStudent();
                break;
            }
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Exiting program. Goodbye! " << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option from the menu. " << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}