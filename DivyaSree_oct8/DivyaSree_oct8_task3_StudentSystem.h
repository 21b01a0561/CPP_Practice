#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include <string>

// Enum class for grade levels
enum class GradeLevel {
    Fail,
    Pass,
    Merit,
    Distinction
};

// Convert grade enum to string
std::string gradeToString(GradeLevel grade);

// ---------------- SubjectScore ----------------
class SubjectScore {
private:
    std::string subjectName;
    int score;
    GradeLevel grade;

public:
    SubjectScore(const std::string& name, int sc, GradeLevel gr);

    void display() const;
    GradeLevel getGrade() const;
    int getScore() const;
};

// ---------------- Student ----------------
class Student {
private:
    SubjectScore** scores;  // dynamic array of pointers
    int maxSubjects;
    int currentCount;

public:
    Student(int max = 10);  // constructor
    ~Student();             // destructor

    void addScore(const SubjectScore& score);
    double computeAverage() const;
    int countDistinctions() const;
    void displayAll() const;
    void displayTopScores() const; // Merit + Distinction
};

#endif
