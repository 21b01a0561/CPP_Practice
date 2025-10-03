#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <initializer_list>

class Quadrilateral {
protected:
    float* sides;   // dynamically allocated array of 4 sides
    float* angles;  // dynamically allocated array of 4 angles
public:
    // Constructor
    Quadrilateral(const float s[4], const float a[4]);
    
    // Copy Constructor
    Quadrilateral(const Quadrilateral& q);
    
    // Assignment Operator
    Quadrilateral& operator=(const Quadrilateral& q);
    
    // Destructor
    virtual ~Quadrilateral();
    
    // Virtual functions
    virtual bool isValid() const;
    virtual float area() const;

    // Operator overloads
    bool operator==(const Quadrilateral& q) const;
    virtual float operator()() const;   // perimeter
    operator float() const;             // area
    virtual void print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Quadrilateral& q);
};

// Derived Classes
class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    void print(std::ostream& out) const override;
};

class Parallelogram : public Trapezoid {
public:
    Parallelogram(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    void print(std::ostream& out) const override;
};

class Rectangle : public Parallelogram {
public:
    Rectangle(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    void print(std::ostream& out) const override;
};

class Square : public Rectangle {
public:
    Square(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    void print(std::ostream& out) const override;
};

#endif
