#include "student1.h"
#include <iostream>
#include <vector>
using namespace std;

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student ID: ";
    int id; cin >> id;
    newStudent.setID(id);
    cout << "Enter name: ";
    string name; cin >> name;
    newStudent.setName(name);
    cout << "Enter age: ";
    int age; cin >> age;
    newStudent.setAge(age);
    cout << "Enter course: ";
    string course; cin >> course;
    newStudent.setCourse(course);

    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void displayStudents(vector<Student>& students) {
    cout << "Student List: " << endl;
    for (auto& student : students) {
        cout << "ID: " << student.getID() << ", Name: " << student.getName()
             << ", Age: " << student.getAge() << ", Course: " << student.getCourse() << endl;
    }
}

void searchStudent(vector<Student>& students) {
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID;

    for (auto& student : students) {
        if (student.getID() == searchID) {
            cout << "Student found: " << endl;
            cout << "ID: " << student.getID() << ", Name: " << student.getName()
                 << ", Age: " << student.getAge() << ", Course: " << student.getCourse() << endl;
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
        if (student.getID() == updateID) {
            cout << "Enter name: ";
            string name; cin >> name; student.setName(name);
            cout << "Enter age: ";
            int age; cin >> age; student.setAge(age);
            cout << "Enter course: ";
            string course; cin >> course; student.setCourse(course);
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
        if (it->getID() == deleteID) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID " << deleteID << " not found." << endl;
}