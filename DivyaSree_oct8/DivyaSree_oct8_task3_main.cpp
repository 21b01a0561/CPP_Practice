#include "DivyaSree_oct8_task3_StudentSystem.h"
#include <iostream>

int main() {
    Student student;

    // Sample Data
    const SubjectScore s1("Math", 92, GradeLevel::Distinction);
    const SubjectScore s2("Physics", 78, GradeLevel::Merit);
    const SubjectScore s3("Chemistry", 65, GradeLevel::Pass);
    const SubjectScore s4("History", 45, GradeLevel::Fail);
    const SubjectScore s5("English", 88, GradeLevel::Distinction);

    // Add scores to student
    student.addScore(s1);
    student.addScore(s2);
    student.addScore(s3);
    student.addScore(s4);
    student.addScore(s5);

    // Display all scores
    student.displayAll();

    // Average score
    std::cout << "\nAverage Score: " << student.computeAverage() << std::endl;

    // Number of distinctions
    const int distinctions = student.countDistinctions();
    std::cout << "Number of Distinctions: " << distinctions << std::endl;

    // Display top scores (Merit + Distinction)
    student.displayTopScores();

    return 0;
}
