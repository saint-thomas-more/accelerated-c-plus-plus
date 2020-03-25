#include "student.h"

// The result is a 70% weighting of exam and 30% to coursework
double calculate_result(Student student) {
    double exam = student.exam * 0.7;
    double coursework = student.coursework * 0.3;
    return exam + coursework;
}