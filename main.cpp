#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

int main() {

    vector<Student> students;
    int choice;

    do {
        cout << "==== STUDENT MANAGEMENT SYSTEM ====" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display students" << endl;
        cout << "3. Search student" << endl;
        cout << "4. Update student" << endl;
        cout << "5. Delete student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
    {
    case 1:
       addStudent(students);
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
       cout << "Exiting..." << endl;
        break;
        
    default:
       cout << "Invalid choice. " << endl;
        break;
    }
    } while (choice != 6);

    return 0;
}