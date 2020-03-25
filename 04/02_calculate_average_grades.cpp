#include <iostream>
#include <vector>
#include <string>
#include "student.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

double calculate_average(const vector<Student>& students) {
    double total = 0;
    for(int i = 0; i < students.size(); i++) {
        Student s = students[i];
        total += calculate_result(s);
    }
    return total / students.size();
}

int main() {
    vector<Student> students;
    Student studentA, studentB;

    studentA.coursework = 50;
    studentA.exam = 75;

    studentB.coursework = 50;
    studentB.exam = 99;

    students.push_back(studentA);
    students.push_back(studentB);

    cout << "Average grade is: " << calculate_average(students) << endl;
}