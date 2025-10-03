#include "Quadrilateral.h"
#include <iostream>
#include <cmath>

// Base class
Quadrilateral::Quadrilateral(const float s[4], const float a[4]) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = s[i];
        angles[i] = a[i];
    }
}

Quadrilateral::Quadrilateral(const Quadrilateral& q) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = q.sides[i];
        angles[i] = q.angles[i];
    }
}

Quadrilateral& Quadrilateral::operator=(const Quadrilateral& q) {
    if (this != &q) {
        delete[] sides;
        delete[] angles;
        sides = new float[4];
        angles = new float[4];
        for (int i = 0; i < 4; i++) {
            sides[i] = q.sides[i];
            angles[i] = q.angles[i];
        }
    }
    return *this;
}

Quadrilateral::~Quadrilateral() {
    delete[] sides;
    delete[] angles;
}

bool Quadrilateral::isValid() const {
    float sum = 0;
    for (int i = 0; i < 4; i++) sum += angles[i];
    return std::abs(sum - 360.0f) < 1e-3;
}

float Quadrilateral::area() const { 
    return 0; 
}

bool Quadrilateral::operator==(const Quadrilateral& q) const {
    return std::abs(this->area() - q.area()) < 1e-3;
}

float Quadrilateral::operator()() const {
    float peri = 0;
    for (int i = 0; i < 4; i++) peri += sides[i];
    return peri;
}

Quadrilateral::operator float() const {
    return area();
}

void Quadrilateral::print(std::ostream& out) const {
    out << "Quadrilateral: sides = [";
    for (int i = 0; i < 4; i++) out << sides[i] << (i < 3 ? ", " : "");
    out << "], angles = [";
    for (int i = 0; i < 4; i++) out << angles[i] << (i < 3 ? ", " : "");
    out << "]";
}

std::ostream& operator<<(std::ostream& out, const Quadrilateral& q) {
    q.print(out);
    return out;
}

// --- Derived Classes ---

Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s,a) {}

bool Trapezoid::isValid() const {
    return Quadrilateral::isValid() && (sides[0] == sides[2] || sides[1] == sides[3]);
}

// Area using trapezoid formula approximation (a + b)/2 * height approximation
float Trapezoid::area() const {
    float height = std::abs(sides[1] * std::sin(angles[0]*M_PI/180.0));
    return ((sides[0] + sides[2]) / 2.0f) * height;
}

void Trapezoid::print(std::ostream& out) const {
    out << "Trapezoid: sides = [";
    for (int i = 0; i < 4; i++) out << sides[i] << (i<3?", ":"");
    out << "], angles = [";
    for (int i = 0; i < 4; i++) out << angles[i] << (i<3?", ":"");
    out << "]";
}

Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s,a) {}

bool Parallelogram::isValid() const {
    return Quadrilateral::isValid() && (sides[0]==sides[2] && sides[1]==sides[3]);
}

float Parallelogram::area() const {
    float height = sides[1] * std::sin(angles[0]*M_PI/180.0);
    return sides[0]*height;
}

void Parallelogram::print(std::ostream& out) const {
    out << "Parallelogram: sides = [";
    for (int i=0;i<4;i++) out << sides[i] << (i<3?", ":"");
    out << "], angles = [";
    for (int i=0;i<4;i++) out << angles[i] << (i<3?", ":"");
    out << "]";
}

Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s,a) {}

bool Rectangle::isValid() const {
    return Quadrilateral::isValid() && (angles[0]==90 && angles[1]==90 && angles[2]==90 && angles[3]==90);
}

float Rectangle::area() const {
    return sides[0]*sides[1];
}

void Rectangle::print(std::ostream& out) const {
    out << "Rectangle: sides = [";
    for(int i=0;i<4;i++) out << sides[i] << (i<3?", ":"");
    out << "]";
}

Square::Square(const float s[4], const float a[4]) : Rectangle(s,a) {}

bool Square::isValid() const {
    bool allSidesEqual = (sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]);
    return Rectangle::isValid() && allSidesEqual;
}

float Square::area() const {
    return sides[0]*sides[0];
}

void Square::print(std::ostream& out) const {
    out << "Square: sides = [";
    for(int i=0;i<4;i++) out << sides[i] << (i<3?", ":"");
    out << "]";
}
