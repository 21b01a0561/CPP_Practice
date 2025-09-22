// Fig. 3.11: GradeBook.h
// GradeBook class definition with course name and instructor name.



#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>   // class GradeBook uses C++ standard string class


// GradeBook class definition
class GradeBook
{
public:
    // constructor that initializes courseName and instructorName
    GradeBook(const std::string& name, const  std::string& instructor);

    // function to set the course name
    void setCourseName(const std::string& name);

    // function to get the course name
    std::string getCourseName() const;

    // function to set the instructor name
    void setInstructorName(const std::string& name);

    // function to get the instructor name
    string getInstructorName() const;

    // function that displays a welcome message
    void displayMessage();

private:
    std::string courseName;     // course name for this GradeBook
    std::string instructorName; // instructor name for this GradeBook
}; // end class GradeBook
