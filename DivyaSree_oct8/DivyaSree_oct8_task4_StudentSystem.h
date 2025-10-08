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

// Convert enum GradeLevel to human-readable string
std::string gradeToString(GradeLevel grade);

// ---------------- SubjectScore Class ----------------
class SubjectScore {
private:
    std::string subjectName;  // Name of the subject
    int score;                // Score obtained
    GradeLevel grade;         // Grade level

public:
    // Constructor to initialize all attributes
    SubjectScore(const std::string& name, int sc, GradeLevel gr);

    void display() const;               // Display subject, score, and grade
    GradeLevel getGrade() const;        // Get grade
    int getScore() const;               // Get numeric score
    const std::string& getSubjectName() const; // Get subject name
};

// ---------------- Student Class ----------------
class Student {
private:
    SubjectScore** scores;    // Dynamic array of pointers to SubjectScore
    int maxSubjects;          // Maximum subjects allowed
    int currentCount;         // Current number of subjects

public:
    Student(int max = 10);    // Constructor with default max = 10
    ~Student();               // Destructor to free memory

    void addScore(const SubjectScore& score);  // Add a subject score
    double computeAverage() const;             // Compute average score
    int countDistinctions() const;             // Count Distinction grades
    void displayAll() const;                   // Display all scores
    void displayTopScores() const;             // Display Merit + Distinction

    int getScoreCount() const;                 // Get number of scores
    const SubjectScore* getScoreAt(int index) const; // Access score by index
};

// ---------------- Global Functions ----------------

// Summarizes grade distribution across all students
void summarizeGrades(Student* students[], int studentCount);

// Finds top scorer in a given subject across all students
const SubjectScore* findTopScorer(Student* students[], int studentCount,
                                  const std::string& subject);

// Exports all Distinction scores to a file
void exportAllDistinctions(Student* students[], int studentCount,
                           const std::string& filename);

#endif
