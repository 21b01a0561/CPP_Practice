#include "RationalNumber.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

// ---------------- Constructor ----------------
RationalNumber::RationalNumber(int num, int denom) {
    if (denom == 0)
        throw std::invalid_argument("Denominator cannot be zero."); // check for zero denominator

    // Ensure denominator is positive
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }

    numerator = num;
    denominator = denom;
    reduce(); // simplify fraction to lowest terms
}

// ---------------- GCD ----------------
int RationalNumber::gcd(int a, int b) {
    return b == 0 ? std::abs(a) : gcd(b, a % b); // recursive Euclidean algorithm
}

// ---------------- Reduce fraction ----------------
void RationalNumber::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

// ---------------- Arithmetic Operators ----------------
RationalNumber RationalNumber::operator+(const RationalNumber& r) const {
    int num = numerator * r.denominator + r.numerator * denominator;
    int denom = denominator * r.denominator;
    return RationalNumber(num, denom); // return simplified sum
}

RationalNumber RationalNumber::operator-(const RationalNumber& r) const {
    int num = numerator * r.denominator - r.numerator * denominator;
    int denom = denominator * r.denominator;
    return RationalNumber(num, denom); // return simplified difference
}

RationalNumber RationalNumber::operator*(const RationalNumber& r) const {
    return RationalNumber(numerator * r.numerator, denominator * r.denominator); // product
}

RationalNumber RationalNumber::operator/(const RationalNumber& r) const {
    if (r.numerator == 0)
        throw std::invalid_argument("Cannot divide by zero."); // prevent division by zero
    return RationalNumber(numerator * r.denominator, denominator * r.numerator); // quotient
}

// ---------------- Relational Operators ----------------
bool RationalNumber::operator==(const RationalNumber& r) const {
    return numerator == r.numerator && denominator == r.denominator;
}

bool RationalNumber::operator!=(const RationalNumber& r) const {
    return !(*this == r);
}

bool RationalNumber::operator<(const RationalNumber& r) const {
    return numerator * r.denominator < r.numerator * denominator; // cross multiplication
}

bool RationalNumber::operator<=(const RationalNumber& r) const {
    return (*this < r) || (*this == r);
}

bool RationalNumber::operator>(const RationalNumber& r) const {
    return !(*this <= r);
}

bool RationalNumber::operator>=(const RationalNumber& r) const {
    return !(*this < r);
}

// ---------------- Output Operator ----------------
std::ostream& operator<<(std::ostream& out, const RationalNumber& r) {
    out << r.numerator << "/" << r.denominator; // display as numerator/denominator
    return out;
}

// ---------------- Input Operator ----------------
std::istream& operator>>(std::istream& in, RationalNumber& r) {
    char slash;
    in >> r.numerator >> slash >> r.denominator; // read input in form a/b
    if (r.denominator == 0)
        throw std::invalid_argument("Denominator cannot be zero."); // check
    if (r.denominator < 0) { // make denominator positive
        r.numerator = -r.numerator;
        r.denominator = -r.denominator;
    }
    r.reduce(); // simplify fraction
    return in;
}
