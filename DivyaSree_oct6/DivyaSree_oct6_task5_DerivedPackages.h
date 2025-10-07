#ifndef DERIVED_PACKAGES_H
#define DERIVED_PACKAGES_H

#include "DivyaSree_oct6_task5_Package.h"

// TwoDayPackage: adds a flat fee
class TwoDayPackage : public Package {
    double flatFee;
public:
    TwoDayPackage(const std::string& sName, const std::string& sAddress,
                  const std::string& sCity, const std::string& sState, const std::string& sZIP,
                  const std::string& rName, const std::string& rAddress,
                  const std::string& rCity, const std::string& rState, const std::string& rZIP,
                  double w, double cost, double fee)
        : Package(sName, sAddress, sCity, sState, sZIP,
                  rName, rAddress, rCity, rState, rZIP, w, cost)
    {
        if (fee < 0.0) throw std::invalid_argument("Flat fee must be non-negative.");
        flatFee = fee;
    }

    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }
};

// OvernightPackage: adds extra fee per ounce
class OvernightPackage : public Package {
    double additionalFeePerOunce;
public:
    OvernightPackage(const std::string& sName, const std::string& sAddress,
                     const std::string& sCity, const std::string& sState, const std::string& sZIP,
                     const std::string& rName, const std::string& rAddress,
                     const std::string& rCity, const std::string& rState, const std::string& rZIP,
                     double w, double cost, double extraFee)
        : Package(sName, sAddress, sCity, sState, sZIP,
                  rName, rAddress, rCity, rState, rZIP, w, cost)
    {
        if (extraFee < 0.0) throw std::invalid_argument("Additional fee must be non-negative.");
        additionalFeePerOunce = extraFee;
    }

    double calculateCost() const override {
        return weight * (costPerOunce + additionalFeePerOunce);
    }
};

#endif
