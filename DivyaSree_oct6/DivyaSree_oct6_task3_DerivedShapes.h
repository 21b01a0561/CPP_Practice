// DerivedShapes.h
// Derived classes for 2D and 3D shapes

#ifndef DERIVED_SHAPES_H
#define DERIVED_SHAPES_H

#include "DivyaSree_oct6_task3_Shape.h"
#include <cmath>

// 2D Shapes
class Circle : public TwoDimensionalShape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    std::string getName() const override { return "Circle"; }
};

class Rectangle : public TwoDimensionalShape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
    std::string getName() const override { return "Rectangle"; }
};

class Square : public Rectangle {
public:
    explicit Square(double side) : Rectangle(side, side) {}
    std::string getName() const override { return "Square"; }
};

class Triangle : public TwoDimensionalShape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    std::string getName() const override { return "Triangle"; }
};

// 3D Shapes
class Sphere : public ThreeDimensionalShape {
    double radius;
public:
    explicit Sphere(double r) : radius(r) {}
    double volume() const override { return (4.0 / 3.0) * 3.14159 * std::pow(radius, 3); }
    std::string getName() const override { return "Sphere"; }
};

class Cube : public ThreeDimensionalShape {
    double side;
public:
    explicit Cube(double s) : side(s) {}
    double volume() const override { return std::pow(side, 3); }
    std::string getName() const override { return "Cube"; }
};

class Cylinder : public ThreeDimensionalShape {
    double radius, height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    double volume() const override { return 3.14159 * radius * radius * height; }
    std::string getName() const override { return "Cylinder"; }
};

#endif
