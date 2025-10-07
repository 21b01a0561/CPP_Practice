#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <stdexcept>

class Package {
protected:
    std::string senderName, senderAddress, senderCity, senderState, senderZIP;
    std::string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight;      // in ounces
    double costPerOunce;

public:
    Package(const std::string& sName, const std::string& sAddress,
            const std::string& sCity, const std::string& sState, const std::string& sZIP,
            const std::string& rName, const std::string& rAddress,
            const std::string& rCity, const std::string& rState, const std::string& rZIP,
            double w, double cost)
        : senderName(sName), senderAddress(sAddress), senderCity(sCity),
          senderState(sState), senderZIP(sZIP),
          recipientName(rName), recipientAddress(rAddress), recipientCity(rCity),
          recipientState(rState), recipientZIP(rZIP)
    {
        if (w <= 0.0) throw std::invalid_argument("Weight must be positive.");
        if (cost <= 0.0) throw std::invalid_argument("Cost per ounce must be positive.");
        weight = w;
        costPerOunce = cost;
    }

    virtual ~Package() {}

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
};
#endif
