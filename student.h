#pragma once
#ifndef STUDENT1_H
#define STUDENT1_H
#include <iostream>
#include <fstream>
#include <string>
#endif // STUDENT1_H

using namespace std; 

struct Student {
private:
    int ID;
    string name;
    int age;
    string course;
public:
    Student(){
        
    }
    Student(int ID, string name, int age, string course) {
        this->ID = ID;
        this->name = name;
        this->age = age;
        this->course = course;
    }
    // Getters
    int getID(){
        return this->ID;
    };
    string getName(){
        return this->name;
    };
    int getAge(){
        return this->age;
    };
    string getCourse(){
        return this->course;
    };

    // Setters
    void setID(int ID){
        this->ID = ID;
    };
    void setName(string name){
        this->name = name;
    };
    void setAge(int age){
        this->age = age;
    };
    void setCourse(string course){
        this->course = course;
    };

    // Destructor
    ~Student() {
    }
};

void addStudent();
void displayStudent();
void searchStudent();
void updateStudent();
void deleteStudent();