#include "Polynomial.h"
#include <iostream>
#include <algorithm>

// ---------------- Default Constructor ----------------
Polynomial::Polynomial() {
    size = 0;
    terms = nullptr;
}

// ---------------- Copy Constructor ----------------
Polynomial::Polynomial(const Polynomial& p) {
    size = p.size;
    if (size > 0) {
        terms = new Term[size];
        for (int i = 0; i < size; i++)
            terms[i] = p.terms[i];
    } else {
        terms = nullptr;
    }
}

// ---------------- Destructor ----------------
Polynomial::~Polynomial() {
    delete[] terms;
}

// ---------------- Set Term ----------------
void Polynomial::setTerm(int index, int coef, int exp) {
    if (index >= size) {
        Term* temp = new Term[index + 1];
        for (int i = 0; i < size; i++)
            temp[i] = terms[i];
        for (int i = size; i <= index; i++)
            temp[i] = {0, 0};
        delete[] terms;
        terms = temp;
        size = index + 1;
    }
    terms[index].coefficient = coef;
    terms[index].exponent = exp;
}

// ---------------- Get Term ----------------
Term Polynomial::getTerm(int index) const {
    if (index >= 0 && index < size)
        return terms[index];
    return {0, 0};
}

// ---------------- Get Size ----------------
int Polynomial::getSize() const {
    return size;
}

// ---------------- Assignment Operator ----------------
Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this != &p) {
        delete[] terms;
        size = p.size;
        if (size > 0) {
            terms = new Term[size];
            for (int i = 0; i < size; i++)
                terms[i] = p.terms[i];
        } else {
            terms = nullptr;
        }
    }
    return *this;
}

// ---------------- Combine Like Terms ----------------
void Polynomial::combineLikeTerms() {
    if (size <= 1) return;

    // sort by exponent descending
    std::sort(terms, terms + size, [](Term a, Term b) { return a.exponent > b.exponent; });

    Term* newTerms = new Term[size];
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (terms[i].coefficient == 0) continue;
        int coef = terms[i].coefficient;
        int exp = terms[i].exponent;
        // combine like exponents
        while (i + 1 < size && terms[i + 1].exponent == exp) {
            coef += terms[i + 1].coefficient;
            i++;
        }
        if (coef != 0) newTerms[newSize++] = {coef, exp};
    }

    delete[] terms;
    terms = newTerms;
    size = newSize;
}

// ---------------- Addition Operator ----------------
Polynomial Polynomial::operator+(const Polynomial& p) const {
    Polynomial result;
    int newSize = size + p.size;
    result.terms = new Term[newSize];
    result.size = newSize;

    for (int i = 0; i < size; i++)
        result.terms[i] = terms[i];
    for (int i = 0; i < p.size; i++)
        result.terms[size + i] = p.terms[i];

    result.combineLikeTerms();
    return result;
}

// ---------------- Subtraction Operator ----------------
Polynomial Polynomial::operator-(const Polynomial& p) const {
    Polynomial negP = p;
    for (int i = 0; i < negP.size; i++)
        negP.terms[i].coefficient *= -1;
    return *this + negP;
}

// ---------------- Multiplication Operator ----------------
Polynomial Polynomial::operator*(const Polynomial& p) const {
    Polynomial result;
    if (size == 0 || p.size == 0) return result;

    int newSize = size * p.size;
    result.terms = new Term[newSize];
    result.size = newSize;

    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < p.size; j++) {
            result.terms[k].coefficient = terms[i].coefficient * p.terms[j].coefficient;
            result.terms[k].exponent = terms[i].exponent + p.terms[j].exponent;
            k++;
        }
    }

    result.combineLikeTerms();
    return result;
}

// ---------------- Compound Assignment Operators ----------------
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    *this = *this + p;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& p) {
    *this = *this - p;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& p) {
    *this = *this * p;
    return *this;
}

// ---------------- Output Operator ----------------
std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    if (p.size == 0) { out << 0; return out; }

    for (int i = 0; i < p.size; i++) {
        if (i > 0 && p.terms[i].coefficient > 0) out << " + ";
        if (p.terms[i].coefficient < 0) out << " - ";
        int coef = std::abs(p.terms[i].coefficient);
        if (coef != 1 || p.terms[i].exponent == 0) out << coef;
        if (p.terms[i].exponent > 0) out << "x";
        if (p.terms[i].exponent > 1) out << "^" << p.terms[i].exponent;
    }
    return out;
}
