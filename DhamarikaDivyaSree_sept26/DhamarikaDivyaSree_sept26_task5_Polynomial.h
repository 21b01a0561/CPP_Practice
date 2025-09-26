#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

struct Term {
    int coefficient;
    int exponent;
};

class Polynomial {
    friend std::ostream& operator<<(std::ostream&, const Polynomial&);
public:
    Polynomial();                              // default constructor
    Polynomial(const Polynomial&);             // copy constructor
    ~Polynomial();                             // destructor

    void setTerm(int index, int coef, int exp); // set term at index
    Term getTerm(int index) const;             // get term at index
    int getSize() const;                       // get number of terms

    // Assignment operator
    Polynomial& operator=(const Polynomial&);

    // Arithmetic operators
    Polynomial operator+(const Polynomial&) const;
    Polynomial operator-(const Polynomial&) const;
    Polynomial operator*(const Polynomial&) const;

    // Compound assignment operators
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial& operator*=(const Polynomial&);

private:
    Term* terms;   // dynamic array of terms
    int size;      // number of terms

    void combineLikeTerms(); // combine terms with same exponent
};

#endif
