#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <string>

class Quadrilateral {
public:
    virtual ~Quadrilateral() {}
    virtual std::string getName() const = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

#endif
