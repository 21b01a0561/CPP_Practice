#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>

class HugeInt {
    friend std::ostream& operator<<(std::ostream&, const HugeInt&);
    friend std::istream& operator>>(std::istream&, HugeInt&);

public:
    static const int digits = 30;  // maximum digits in a HugeInt

    // Constructors
    HugeInt(long = 0);
    HugeInt(const std::string&);

    // Arithmetic operators
    HugeInt operator+(const HugeInt&) const;    // HugeInt + HugeInt
    HugeInt operator+(int) const;               // HugeInt + int
    HugeInt operator+(const std::string&) const;// HugeInt + string
    HugeInt operator*(const HugeInt&) const;    // multiplication
    HugeInt operator/(const HugeInt&) const;    // division

    // Relational operators
    bool operator==(const HugeInt&) const;
    bool operator!=(const HugeInt&) const;
    bool operator<(const HugeInt&) const;
    bool operator<=(const HugeInt&) const;
    bool operator>(const HugeInt&) const;
    bool operator>=(const HugeInt&) const;

private:
    short integer[digits];  // each element stores a single digit
};

#endif
