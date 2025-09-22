// Fig. 3.12: GradeBook.cpp
// GradeBook member-function definitions.
// This file contains the implementations of the functions declared in GradeBook.h

#include <iostream>     // allows program to output data to the screen
#include "GradeBook.h"  // include definition of class GradeBook


// constructor initializes courseName and instructorName with strings supplied as arguments
GradeBook::GradeBook(const std::string& name,const std::string& instructor)
{
    setCourseName(name);          // call set function to initialize courseName
    setInstructorName(instructor); // call set function to initialize instructorName
}

// function to set the course name
void GradeBook::setCourseName(const std::string& name)
{
    courseName = name; // store the course name in the object
}

// function to get the course name
std::string GradeBook::getCourseName() const
{
    return courseName; // return object's courseName
}

// function to set the instructor name
void GradeBook::setInstructorName(const std::string& name)
{
    instructorName = name; // store the instructor name in the object
}

// function to get the instructor name
std::string GradeBook::getInstructorName() const
{c
    return instructorName; // return object's instructorName
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    std::cout << "Welcome to the grade book for\n" << getCourseName()
         << "!" << std::endl; // print welcome message and course name
    std::cout << "This course is presented by: " << getInstructorName() << std::endl; 
    // print instructor name
}
