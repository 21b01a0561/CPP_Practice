#include "DoubleSubscriptedArray.h"
#include <iomanip>
#include <stdexcept>

// Constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c)
    : rows(r > 0 ? r : 1), cols(c > 0 ? c : 1) { // check for positive size and if not set to 1 as default
    ptr = new int[rows * cols]();
}

// Copy constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& other)
    : rows(other.rows), cols(other.cols) {
    ptr = new int[rows * cols];    // allocate new memory
    for (int i = 0; i < rows * cols; i++) {
        ptr[i] = other.ptr[i];     // copy each element
    }
}

// Destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] ptr;     // free memory
}

// Assignment operator- checks for self assignments
DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& right) {
    if (this != &right) {  // prevent the self-assignment
        if (rows * cols != right.rows * right.cols) {  // if size is different
            delete[] ptr;
            rows = right.rows;
            cols = right.cols;
            ptr = new int[rows * cols];
        }
        for (int i = 0; i < rows * cols; i++) {   // for copying elements
            ptr[i] = right.ptr[i];
        }
    }
    return *this; // return current object
}

// Equality operator- checks for all elements are equality and also the dimensions
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& right) const {
    if (rows != right.rows || cols != right.cols) {
        return false;    //if different size found return false
    }
    for (int i = 0; i < rows * cols; i++) {
        if (ptr[i] != right.ptr[i]) {
            return false;      if different elements found return false
        }
    }
    return true;    returns true if all are equal
}

// Inequality operator
bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& right) const {
    return !(*this == right);
}

// Overloaded () operator without const
int& DoubleSubscriptedArray::operator()(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Subscript out of range"); // validate the indices
    }
    return ptr[r * cols + c];  
}

// Overloaded () operator with const
const int& DoubleSubscriptedArray::operator()(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Subscript out of range");
    }
    return ptr[r * cols + c];
}
 
// Getters for both rows and columns
int DoubleSubscriptedArray::getRows() const { return rows; }
int DoubleSubscriptedArray::getCols() const { return cols; }

// Input operator- reads all elements row by row
std::istream& operator>>(std::istream& in, DoubleSubscriptedArray& a) {
    for (int i = 0; i < a.rows * a.cols; i++) {
        in >> a.ptr[i];
    }
    return in;
}

// Output operator - prints array in rxc format
std::ostream& operator<<(std::ostream& out, const DoubleSubscriptedArray& a) {
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            out << std::setw(5) << a.ptr[i * a.cols + j];
        }
        out << '\n';
    }
    return out;
}
