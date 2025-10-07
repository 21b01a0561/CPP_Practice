// main.cpp
// Display area and volume of shapes

#include "DivyaSree_oct6_task3_DerivedShapes.h"
#include <vector>
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "=== Two-Dimensional Shapes ===\n\n";

    std::vector<TwoDimensionalShape*> twoDShapes = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Square(3.5),
        new Triangle(6.0, 4.0)
    };

    for (const auto* shape : twoDShapes) {
        std::cout << shape->getName() << " area: "
                  << std::fixed << std::setprecision(2) << shape->area() << "\n";
    }

    for (auto* shape : twoDShapes)
        delete shape;

    std::cout << "\n=== Three-Dimensional Shapes ===\n\n";

    std::vector<ThreeDimensionalShape*> threeDShapes = {
        new Sphere(3.0),
        new Cube(2.0),
        new Cylinder(2.0, 5.0)
    };

    for (const auto* shape : threeDShapes) {
        std::cout << shape->getName() << " volume: "
                  << std::fixed << std::setprecision(2) << shape->volume() << "\n";
    }

    for (auto* shape : threeDShapes)
        delete shape;

    return 0;
}
