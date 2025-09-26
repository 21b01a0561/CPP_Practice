#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>

class DoubleSubscriptedArray {
private:
    int rows;
    int cols;
    int* ptr;  // dynamically allocated 1D array

public:
    // Constructor
    explicit DoubleSubscriptedArray(int r = 1, int c = 1);

    // Copy constructor
    DoubleSubscriptedArray(const DoubleSubscriptedArray& other);

    // Destructor
    ~DoubleSubscriptedArray();

    // Assignment operator
    DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& right);

    // Equality and inequality operators
    bool operator==(const DoubleSubscriptedArray& right) const;
    bool operator!=(const DoubleSubscriptedArray& right) const;

    // Overloaded () operator
    int& operator()(int r, int c);
    const int& operator()(int r, int c) const;

    // Getters for rows and col
    int getRows() const;
    int getCols() const;

    // Friends for input and output
    friend std::istream& operator>>(std::istream& in, DoubleSubscriptedArray& a);
    friend std::ostream& operator<<(std::ostream& out, const DoubleSubscriptedArray& a);
};

#endif
