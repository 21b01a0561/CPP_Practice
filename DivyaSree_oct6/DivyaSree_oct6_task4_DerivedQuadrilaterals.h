#ifndef DERIVED_QUADRILATERALS_H
#define DERIVED_QUADRILATERALS_H

#include "DivyaSree_oct6_task4_Quadrilateral.h"
#include <cmath>

// Trapezoid
class Trapezoid : public Quadrilateral {
    double a, b, h; // a,b: parallel sides, h: height
public:
    Trapezoid(double sideA, double sideB, double height) : a(sideA), b(sideB), h(height) {}
    double area() const override { return 0.5 * (a + b) * h; }
    double perimeter() const override { return a + b + 2 * h; } // simplified
    std::string getName() const override { return "Trapezoid"; }
};

// Parallelogram
class Parallelogram : public Quadrilateral {
    double base, side, height;
public:
    Parallelogram(double b, double s, double h) : base(b), side(s), height(h) {}
    double area() const override { return base * height; }
    double perimeter() const override { return 2 * (base + side); }
    std::string getName() const override { return "Parallelogram"; }
};

// Rectangle
class Rectangle : public Parallelogram {
public:
    Rectangle(double length, double width)
        : Parallelogram(length, width, width) {} // height = width
    std::string getName() const override { return "Rectangle"; }
    double area() const override { return Parallelogram::area(); }
    double perimeter() const override { return Parallelogram::perimeter(); }
};

// Square
class Square : public Rectangle {
public:
    explicit Square(double side) : Rectangle(side, side) {}
    std::string getName() const override { return "Square"; }
    double area() const override { return Rectangle::area(); }
    double perimeter() const override { return Rectangle::perimeter(); }
};

#endif
