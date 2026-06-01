#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Student {
public:
    string rollNumber;
    string name;
    int age;

    string toCSV() const {
        return rollNumber + "," + name + "," + to_string(age);
    }
};

const int MAX_STUDENTS = 100;

int loadStudents(Student students[]) {
    ifstream inFile("student.txt");
    if (!inFile) {
        return 0; 
    }

    int count = 0;
    string line;
    while (getline(inFile, line) && count < MAX_STUDENTS) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string roll, nameStr, ageStr;

        if (getline(ss, roll, ',') && getline(ss, nameStr, ',') && getline(ss, ageStr, ',')) {
            students[count].rollNumber = roll;
            students[count].name = nameStr;
            students[count].age = stoi(ageStr);
            count++;
        }
    }
    inFile.close();
    return count;
}

void saveStudents(const Student students[], int count) {
    ofstream outFile("student.txt");
    for (int i = 0; i < count; i++) {
        outFile << students[i].toCSV() << endl;
    }
    outFile.close();
}

void displayAllStudents() {
    Student students[MAX_STUDENTS];
    int count = loadStudents(students);

    if (count == 0) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    cout << "Roll Number\tName\t\tAge\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << students[i].rollNumber << "\t\t" 
             << students[i].name << "\t\t" 
             << students[i].age << "\n";
    }
}

void searchStudent() {
    string searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    Student students[MAX_STUDENTS];
    int count = loadStudents(students);
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == searchRoll) {
            cout << "\nStudent Details Found:\n";
            cout << "Roll Number: " << students[i].rollNumber << "\n";
            cout << "Name:        " << students[i].name << "\n";
            cout << "Age:         " << students[i].age << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found\n";
    }
}

void updateStudent() {
    string targetRoll;
    cout << "\nEnter Roll Number to update: ";
    cin >> targetRoll;

    Student students[MAX_STUDENTS];
    int count = loadStudents(students);
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == targetRoll) {
            cout << "\nCurrent details: " << students[i].name << " (Age: " << students[i].age << ")\n";
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new Age: ";
            cin >> students[i].age;

            saveStudents(students, count);
            cout << "\nStudent information updated successfully and saved permanently.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found\n";
    }
}

void deleteStudent() {
    string targetRoll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> targetRoll;

    Student students[MAX_STUDENTS];
    int count = loadStudents(students);
    int targetIndex = -1;

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == targetRoll) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex != -1) {
        for (int i = targetIndex; i < count - 1; i++) {
            students[i] = students[i + 1];
        }
        count--; 

        saveStudents(students, count);
        cout << "\nRecord removed permanently from the file.\n";
    } else {
        cout << "\nStudent not found\n";
    }
}

void addStudent() {
    Student s;
    cout << "\nEnter Roll Number: ";
    cin >> s.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;

    ofstream outFile("student.txt", ios::app);
    outFile << s.toCSV() << endl;
    outFile.close();
    cout << "\nRecord added successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM   \n";
        cout << "===============================\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "6. Add New Student (Helper Option)\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllStudents();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "\nExiting program. Goodbye!\n";
                break;
            case 6:
                addStudent();
                break;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 6.\n";
        }
    } while (choice != 5);

    return 0;
}