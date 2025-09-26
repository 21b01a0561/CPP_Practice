// Complex.cpp
#include "Complex.h"

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart) {}


// Addition operator
Complex Complex::operator+(const Complex& operand2) const {
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}// end function of operator+

// Subtraction operator
Complex Complex::operator-(const Complex& operand2) const {
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
} //end function of operator-


// Multiplication
Complex Complex::operator*(const Complex& operand2) const {
    return Complex(
        real * operand2.real - imaginary * operand2.imaginary, // (ac - bd)
        real * operand2.imaginary + imaginary * operand2.real  // (ad + bc)
    );
} end function of operator*


// Equality
bool Complex::operator==(const Complex& right) const {
    return (real == right.real && imaginary == right.imaginary);
}  end function of operator==

// Inequality
bool Complex::operator!=(const Complex& right) const {
    return !(*this == right);
}end function of operator!=



// Output operator <<
std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << "(" << c.real << ", " << c.imaginary << ")";
    return out;
}

// Input operator >>
std::istream& operator>>(std::istream& in, Complex& c) {
    in >> c.real >> c.imaginary;
    return in;
}
