// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    // Constructor
    Complex(double = 0.0, double = 0.0);

    // Arithmetic operators
    Complex operator+(const Complex&) const;//addition
    Complex operator-(const Complex&) const;//subtraction
    Complex operator*(const Complex&) const; // multiplication

    // Comparison operators
    bool operator==(const Complex&) const;//equality
    bool operator!=(const Complex&) const;//Inequality

    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);

private:
    double real;       // real part
    double imaginary;  // imaginary part
};

#endif
