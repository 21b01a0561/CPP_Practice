
// Member-function definitions for class Invoice

#include "Invoice.h"
#include <iostream> // for std::cout

// constructor initializes data members with validation
Invoice::Invoice(const std::string& partNum,
                 const std::string& partDesc,
                 int qty,
                 double price)
    : partNumber(partNum),
      partDescription(partDesc),
      quantity(qty >= 0 ? qty : 0),
      pricePerItem(price >= 0.0 ? price : 0.0)
{
    // print warning if quantity is invalid
    if (qty < 0)
    {
        std::cout << "Warning: Quantity cannot be negative. Setting to 0." << std::endl;
    }
    // print warning if price is invalid
    if (price < 0.0)
    {
        std::cout << "Warning: Price per item cannot be negative. Setting to 0." << std::endl;
    }
}

// set and get functions for partNumber
void Invoice::setPartNumber(const std::string& partNum)
{
    partNumber = partNum; // store part number
}

std::string Invoice::getPartNumber() const
{
    return partNumber; // return part number
}

// set and get functions for partDescription
void Invoice::setPartDescription(const std::string& partDesc)
{
    partDescription = partDesc; // store part description
}

std::string Invoice::getPartDescription() const
{
    return partDescription; // return part description
}

// set and get functions for quantity
void Invoice::setQuantity(int qty)
{
    quantity = (qty >= 0 ? qty : 0); // validate quantity
    if (qty < 0)
    {
        std::cout << "Warning: Quantity cannot be negative. Setting to 0." << std::endl;
    }
}

int Invoice::getQuantity() const
{
    return quantity; // return quantity
}

// set and get functions for pricePerItem
void Invoice::setPricePerItem(double price)
{
    pricePerItem = (price >= 0.0 ? price : 0.0); // validate price
    if (price < 0.0)
    {
        std::cout << "Warning: Price per item cannot be negative. Setting to 0." << std::endl;
    }
}

double Invoice::getPricePerItem() const
{
    return pricePerItem; // return price per item
}

// calculate and return invoice amount
double Invoice::getInvoiceAmount() const
{
    return quantity * pricePerItem; // multiply quantity by price
}
