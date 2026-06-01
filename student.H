#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    int ID;
    std::string name;
    int age;
    std::string course;
};

void addStudent(std::vector<Student>& student);
void displayStudents(const std::vector<Student>& student);
void searchStudent(const std::vector<Student>& student);
void updateStudent(std::vector<Student>& student);
void deleteStudent(std::vector<Student>& student);

#endif // STUDENT_H