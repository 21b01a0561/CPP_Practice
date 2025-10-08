#include "DivyaSree_oct8_task3_StudentSystem.h"
#include <iostream>

// ---------------- SubjectScore Implementation ----------------
std::string gradeToString(GradeLevel grade) {
    switch (grade) {
        case GradeLevel::Fail: return "Fail";
        case GradeLevel::Pass: return "Pass";
        case GradeLevel::Merit: return "Merit";
        case GradeLevel::Distinction: return "Distinction";
        default: return "Unknown";
    }
}

SubjectScore::SubjectScore(const std::string& name, int sc, GradeLevel gr)
    : subjectName(name), score(sc), grade(gr) {}

void SubjectScore::display() const {
    std::cout << "Subject: " << subjectName
              << " | Score: " << score
              << " | Grade: " << gradeToString(grade)
              << std::endl;
}

GradeLevel SubjectScore::getGrade() const {
    return grade;
}

int SubjectScore::getScore() const {
    return score;
}

// ---------------- Student Implementation ----------------
Student::Student(int max)
    : maxSubjects(max), currentCount(0) {
    scores = new SubjectScore*[maxSubjects]; // dynamic allocation
}

Student::~Student() {
    for (int i = 0; i < currentCount; ++i) {
        delete scores[i];  // delete each SubjectScore object
    }
    delete[] scores;       // delete the array
}

void Student::addScore(const SubjectScore& score) {
    if (currentCount < maxSubjects) {
        scores[currentCount++] = new SubjectScore(score);
    } else {
        std::cout << "Cannot add more scores, max reached!" << std::endl;
    }
}

double Student::computeAverage() const {
    if (currentCount == 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < currentCount; ++i) {
        sum += scores[i]->getScore();
    }
    return static_cast<double>(sum) / currentCount;
}

int Student::countDistinctions() const {
    int count = 0;
    for (int i = 0; i < currentCount; ++i) {
        if (scores[i]->getGrade() == GradeLevel::Distinction) ++count;
    }
    return count;
}

void Student::displayAll() const {
    std::cout << "\n=== All Scores ===" << std::endl;
    for (int i = 0; i < currentCount; ++i) {
        scores[i]->display();
    }
}

void Student::displayTopScores() const {
    std::cout << "\n=== Top Scores (Merit + Distinction) ===" << std::endl;
    for (int i = 0; i < currentCount; ++i) {
        GradeLevel gr = scores[i]->getGrade();
        if (gr == GradeLevel::Merit || gr == GradeLevel::Distinction) {
            scores[i]->display();
        }
    }
}
