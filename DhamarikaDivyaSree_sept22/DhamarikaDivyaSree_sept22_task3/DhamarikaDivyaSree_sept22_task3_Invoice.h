// Invoice.h
// Definition of class Invoice that represents a store invoice

#ifndef INVOICE_H
#define INVOICE_H

#include <string> // for std::string

class Invoice
{
public:
    // constructor initializes all data members with validation
    Invoice(const std::string& partNum,
            const std::string& partDesc,
            int qty,
            double price);

    // set and get functions for partNumber
    void setPartNumber(const std::string& partNum);
    std::string getPartNumber() const;

    // set and get functions for partDescription
    void setPartDescription(const std::string& partDesc);
    std::string getPartDescription() const;

    // set and get functions for quantity
    void setQuantity(int qty);
    int getQuantity() const;

    // set and get functions for pricePerItem
    void setPricePerItem(double price);
    double getPricePerItem() const;

    // calculate and return invoice amount (quantity * pricePerItem)
    double getInvoiceAmount() const;

private:
    std::string partNumber;      // part number
    std::string partDescription; // part description
    int quantity;                // quantity purchased
    double pricePerItem;         // price per item
};

#endif
