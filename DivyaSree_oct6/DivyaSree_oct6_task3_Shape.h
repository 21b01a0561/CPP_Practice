// Shape.h
// Base class hierarchy for 2D and 3D shapes

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual ~Shape() {}
    virtual std::string getName() const = 0;
};

// 2D Shape base class
class TwoDimensionalShape : public Shape {
public:
    virtual double area() const = 0;
};

// 3D Shape base class
class ThreeDimensionalShape : public Shape {
public:
    virtual double volume() const = 0;
};

#endif
