#include "DivyaSree_oct8_task4_StudentSystem.h"
#include <iostream>

int main() {
    // Create array of Student pointers
    const int studentCount = 3;
    Student* students[studentCount];

    // Allocate students
    students[0] = new Student();
    students[1] = new Student();
    students[2] = new Student();

    // Populate sample scores for each student
    students[0]->addScore(SubjectScore("Math", 95, GradeLevel::Distinction));
    students[0]->addScore(SubjectScore("Physics", 80, GradeLevel::Merit));
    students[0]->addScore(SubjectScore("Chemistry", 70, GradeLevel::Pass));

    students[1]->addScore(SubjectScore("Math", 88, GradeLevel::Merit));
    students[1]->addScore(SubjectScore("History", 60, GradeLevel::Pass));
    students[1]->addScore(SubjectScore("English", 92, GradeLevel::Distinction));

    students[2]->addScore(SubjectScore("Math", 99, GradeLevel::Distinction));
    students[2]->addScore(SubjectScore("Physics", 50, GradeLevel::Fail));
    students[2]->addScore(SubjectScore("English", 85, GradeLevel::Merit));

    // 1. Display grade summary across all students
    summarizeGrades(students, studentCount);

    // 2. Find top scorer in Math
    const SubjectScore* topMath = findTopScorer(students, studentCount, "Math");
    if (topMath) {
        std::cout << "\nTop scorer in Math:\n";
        topMath->display();
    } else {
        std::cout << "\nNo Math scores found.\n";
    }

    // 3. Export all Distinction scores to file
    exportAllDistinctions(students, studentCount, "distinctions.txt");

    // Clean up dynamically allocated students
    for (int i = 0; i < studentCount; ++i)
        delete students[i];

    return 0;
}
