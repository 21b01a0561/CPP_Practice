#include "DivyaSree_oct1_task3_Quadrilateral.h"
#include <iostream>

int main() {
    const float sqSides[4] = {5,5,5,5};
    const float sqAngles[4] = {90,90,90,90};
    const float rectSides[4] = {6,4,6,4};
    const float rectAngles[4] = {90,90,90,90};
    const float paraSides[4] = {6,4,6,4};
    const float paraAngles[4] = {110,70,110,70};
    const float trapSides[4] = {6,5,4,3};
    const float trapAngles[4] = {100,80,100,80};
    const float quadSides[4] = {3,4,5,6};
    const float quadAngles[4] = {90,90,90,90};

    Quadrilateral* shapes[5];
    shapes[0] = new Quadrilateral(quadSides, quadAngles);
    shapes[1] = new Trapezoid(trapSides, trapAngles);
    shapes[2] = new Parallelogram(paraSides, paraAngles);
    shapes[3] = new Rectangle(rectSides, rectAngles);
    shapes[4] = new Square(sqSides, sqAngles);

    for(int i=0;i<5;i++) {
        std::cout << *shapes[i] << std::endl;
        std::cout << "Valid: " << (shapes[i]->isValid() ? "Yes":"No") << std::endl;
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << (*shapes[i])() << std::endl;
        std::cout << "Float area: " << float(*shapes[i]) << std::endl << std::endl;
    }

    if(*shapes[3] == *shapes[4]) std::cout << "Rectangle and Square have equal area.\n";
    else std::cout << "Rectangle and Square have different area.\n";

    for(int i=0;i<5;i++) delete shapes[i];

    return 0;
}

