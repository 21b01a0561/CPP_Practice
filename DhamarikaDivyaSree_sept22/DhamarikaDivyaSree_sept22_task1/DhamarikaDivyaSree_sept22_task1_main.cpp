//  main.cpp
// GradeBook test program that demonstrates course name and instructor name.

#include <iostream>    // allows program to output data to the screen
#include "GradeBook.h" // include definition of class GradeBook


// main function begins program execution
int main()
{
    // create a GradeBook object with a course name and an instructor name
    GradeBook myGradeBook("CS101 Introduction to C++ Programming", "Dr. Smith");

    // display welcome message with course and instructor
    myGradeBook.displayMessage();

    std::cout << "\nChanging instructor...\n" << std::endl;

    // change instructor and display again
    myGradeBook.setInstructorName("Prof. Johnson");
    myGradeBook.displayMessage();

    return 0; // indicate successful termination
} // end main
