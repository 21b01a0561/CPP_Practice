#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream&, const RationalNumber&);
    friend std::istream& operator>>(std::istream&, RationalNumber&);

public:
    // Constructor with default numerator=0, denominator=1
    RationalNumber(int numerator = 0, int denominator = 1);

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber&) const;//addition
    RationalNumber operator-(const RationalNumber&) const;//subtraction
    RationalNumber operator*(const RationalNumber&) const;//multiplication
    RationalNumber operator/(const RationalNumber&) const;//division

    // Relational operators
    bool operator==(const RationalNumber&) const;//equality
    bool operator!=(const RationalNumber&) const;//inequality
    bool operator<(const RationalNumber&) const;//less than
    bool operator<=(const RationalNumber&) const;//less than or equal
    bool operator>(const RationalNumber&) const;//greater than
    bool operator>=(const RationalNumber&) const;//greater than or equal

private:
    int numerator;    // numerator of fraction
    int denominator;  // denominator of fraction

    void reduce();                 // simplify fraction to lowest terms
    static int gcd(int a, int b);  // calculate gcd
};

#endif
