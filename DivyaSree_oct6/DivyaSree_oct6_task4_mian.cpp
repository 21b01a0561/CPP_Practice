#include "DivyaSree_oct6_task4_DerivedQuadrilaterals.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Quadrilateral*> shapes = {
        new Trapezoid(5, 7, 4),
        new Parallelogram(6, 3, 4),
        new Rectangle(5, 3),
        new Square(4)
    };

    for (auto* shape : shapes) {
        std::cout << shape->getName() << std::endl;
        std::cout << "Area: " << shape->area() << std::endl;
        std::cout << "Perimeter: " << shape->perimeter() << std::endl;
        std::cout << std::endl;
    }

    for (auto* shape : shapes)
        delete shape;

    return 0;
}
