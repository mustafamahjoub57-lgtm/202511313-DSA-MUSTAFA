#include "student.h"
#include <iostream>
#include <vector>
using namespace std;

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student ID: ";
    cin >> newStudent.ID;
    cout << "Enter name: ";
    cin >> newStudent.name;
    cout << "Enter age: ";
    cin >> newStudent.age;
    cout << "Enter course: ";
    cin >> newStudent.course;

    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void displayStudents(const vector<Student>& students) {
    cout << "Student List: " << endl;
    for (const auto& student : students) {
        cout << "ID: " << student.ID << ", Name: " << student.name 
             << ", Age: " << student.age << ", Course: " << student.course << endl;
    }
}

void searchStudent(const vector<Student>& students) {
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID;

    for (const auto& student : students) {
        if (student.ID == searchID) {
            cout << "Student found: " << endl;
            cout << "ID: " << student.ID << ", Name: " << student.name 
                 << ", Age: " << student.age << ", Course: " << student.course << endl;
            return;
        }
    }
    cout << "Student with ID " << searchID << " not found." << endl;
}

void updateStudent(vector<Student>& students) {
    int updateID;
    cout << "Enter student ID to update: ";
    cin >> updateID;

    for (auto& student : students) {
        if (student.ID == updateID) {
            cout << "Enter name: ";
            cin >> student.name;
            cout << "Enter age: ";
            cin >> student.age;
            cout << "Enter course: ";
            cin >> student.course;
            cout << "Student updated successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID " << updateID << " not found." << endl;
}

void deleteStudent(vector<Student>& students) {
    int deleteID;
    cout << "Enter student ID to delete: ";
    cin >> deleteID;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->ID == deleteID) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID " << deleteID << " not found." << endl;
}