#include "DivyaSree_oct8_task4_StudentSystem.h"
#include <iostream>
#include <fstream>

// ---------------- SubjectScore Implementation ----------------

// Convert enum grade to string
std::string gradeToString(GradeLevel grade) {
    switch (grade) {
        case GradeLevel::Fail: return "Fail";
        case GradeLevel::Pass: return "Pass";
        case GradeLevel::Merit: return "Merit";
        case GradeLevel::Distinction: return "Distinction";
        default: return "Unknown";
    }
}

// Constructor initializes all attributes
SubjectScore::SubjectScore(const std::string& name, int sc, GradeLevel gr)
    : subjectName(name), score(sc), grade(gr) {}

// Display subject details
void SubjectScore::display() const {
    std::cout << "Subject: " << subjectName
              << " | Score: " << score
              << " | Grade: " << gradeToString(grade)
              << std::endl;
}

GradeLevel SubjectScore::getGrade() const { return grade; }
int SubjectScore::getScore() const { return score; }
const std::string& SubjectScore::getSubjectName() const { return subjectName; }

// ---------------- Student Implementation ----------------

// Constructor allocates dynamic array for scores
Student::Student(int max) : maxSubjects(max), currentCount(0) {
    scores = new SubjectScore*[maxSubjects];
}

// Destructor frees all dynamically allocated SubjectScore objects
Student::~Student() {
    for (int i = 0; i < currentCount; ++i)
        delete scores[i];
    delete[] scores;
}

// Add a new SubjectScore to the student
void Student::addScore(const SubjectScore& score) {
    if (currentCount < maxSubjects)
        scores[currentCount++] = new SubjectScore(score);
}

// Compute average score across all subjects
double Student::computeAverage() const {
    if (currentCount == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < currentCount; ++i)
        sum += scores[i]->getScore();
    return static_cast<double>(sum) / currentCount;
}

// Count how many subjects have Distinction grade
int Student::countDistinctions() const {
    int count = 0;
    for (int i = 0; i < currentCount; ++i)
        if (scores[i]->getGrade() == GradeLevel::Distinction)
            ++count;
    return count;
}

// Display all subject scores
void Student::displayAll() const {
    std::cout << "\n=== All Scores ===" << std::endl;
    for (int i = 0; i < currentCount; ++i)
        scores[i]->display();
}

// Display top scores (Merit + Distinction)
void Student::displayTopScores() const {
    std::cout << "\n=== Top Scores (Merit + Distinction) ===" << std::endl;
    for (int i = 0; i < currentCount; ++i) {
        GradeLevel gr = scores[i]->getGrade();
        if (gr == GradeLevel::Merit || gr == GradeLevel::Distinction)
            scores[i]->display();
    }
}

// Return current number of scores
int Student::getScoreCount() const { return currentCount; }

// Access a score by index safely
const SubjectScore* Student::getScoreAt(int index) const {
    if (index >= 0 && index < currentCount)
        return scores[index];
    return nullptr;
}

// ---------------- Global Functions ----------------

// Summarize grade distribution across all students
void summarizeGrades(Student* students[], int studentCount) {
    int fail = 0, pass = 0, merit = 0, distinction = 0;
    for (int i = 0; i < studentCount; ++i) {
        if (!students[i]) continue; // Skip nullptr student
        for (int j = 0; j < students[i]->getScoreCount(); ++j) {
            const SubjectScore* s = students[i]->getScoreAt(j);
            if (!s) continue;
            switch (s->getGrade()) {
                case GradeLevel::Fail: ++fail; break;
                case GradeLevel::Pass: ++pass; break;
                case GradeLevel::Merit: ++merit; break;
                case GradeLevel::Distinction: ++distinction; break;
            }
        }
    }
    std::cout << "\n=== Grade Summary Across Students ===\n";
    std::cout << "Fail: " << fail << "\nPass: " << pass
              << "\nMerit: " << merit << "\nDistinction: " << distinction << std::endl;
}

// Find top scorer for a specific subject across all students
const SubjectScore* findTopScorer(Student* students[], int studentCount,
                                  const std::string& subject) {
    const SubjectScore* top = nullptr;
    for (int i = 0; i < studentCount; ++i) {
        if (!students[i]) continue;
        for (int j = 0; j < students[i]->getScoreCount(); ++j) {
            const SubjectScore* s = students[i]->getScoreAt(j);
            if (!s || s->getSubjectName() != subject) continue;
            if (!top || s->getScore() > top->getScore())
                top = s;
        }
    }
    return top; // Returns nullptr if subject not found
}

// Export all Distinction scores to a file
void exportAllDistinctions(Student* students[], int studentCount,
                           const std::string& filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }
    for (int i = 0; i < studentCount; ++i) {
        if (!students[i]) continue;
        for (int j = 0; j < students[i]->getScoreCount(); ++j) {
            const SubjectScore* s = students[i]->getScoreAt(j);
            if (s && s->getGrade() == GradeLevel::Distinction) {
                out << "Student[" << i << "] | Subject: " << s->getSubjectName()
                    << " | Score: " << s->getScore() << "\n";
            }
        }
    }
    out.close();
    std::cout << "All Distinction scores exported to " << filename << std::endl;
}
