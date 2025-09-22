// main.cpp
// Test program for class Invoice

#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision
#include "Invoice.h"

int main()
{
    // format output to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    // create two Invoice objects
    Invoice invoice1("A101", "Hammer", 5, 12.50);
    Invoice invoice2("B202", "Nails", -10, -0.25); // invalid values

    // display invoice1 details
    std::cout << "Invoice1:" << std::endl;
    std::cout << "Part Number: " << invoice1.getPartNumber() << std::endl;
    std::cout << "Description: " << invoice1.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice1.getQuantity() << std::endl;
    std::cout << "Price per item: $" << invoice1.getPricePerItem() << std::endl;
    std::cout << "Invoice amount: $" << invoice1.getInvoiceAmount() << "\n" << std::endl;

    // display invoice2 details
    std::cout << "Invoice2:" << std::endl;
    std::cout << "Part Number: " << invoice2.getPartNumber() << std::endl;
    std::cout << "Description: " << invoice2.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice2.getQuantity() << std::endl;
    std::cout << "Price per item: $" << invoice2.getPricePerItem() << std::endl;
    std::cout << "Invoice amount: $" << invoice2.getInvoiceAmount() << std::endl;

    return 0;
}
