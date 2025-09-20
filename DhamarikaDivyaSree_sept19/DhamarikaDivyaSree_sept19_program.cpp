#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

// Class
class ServiceRecord {
private:
    std::string date_;
    int mileage_;
    std::string description_;

public:
    // Constructors
    ServiceRecord() : date_(""), mileage_(0), description_("") {}
    ServiceRecord(const std::string& date, int mileage, const std::string& desc)
        : date_(date), mileage_(mileage), description_(desc) {
        if (mileage < 0) throw std::invalid_argument("Mileage cannot be negative");
    }
    ServiceRecord(const ServiceRecord& other)
        : date_(other.date_), mileage_(other.mileage_), description_(other.description_) {}
    ServiceRecord& operator=(const ServiceRecord& other) {
        if (this != &other) {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }
        return *this;
    }

    // Getters
    const std::string& getDate() const { return date_; }
    int getMileage() const { return mileage_; }
    const std::string& getDescription() const { return description_; }

    // Utility
    void print() const {
        std::cout << "  [" << date_ << "] " << mileage_ << " km - " << description_ << std::endl;
    }
};

// Car class
class Car {
private:
    std::string vin_;
    std::string make_;
    std::string model_;
    double price_;
    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;

    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;

    static size_t totalCars_;

   
public:
    // Default Constructor
    Car() : vin_(""), make_(""), model_(""), price_(0),
            serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
            damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        totalCars_++;
    }
  // Parameterized Constructor
    Car(const std::string& vin, const std::string& make, const std::string& model, double price)
        : vin_(vin), make_(make), model_(model), price_(price),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        if (price < 0) throw std::invalid_argument("Price cannot be negative");
        totalCars_++;
    }
     // Copy Constructor
    Car(const Car& other) : vin_(other.vin_), make_(other.make_),
        model_(other.model_), price_(other.price_),
        serviceCount_(other.serviceCount_), serviceCap_(other.serviceCap_),
        damageCount_(other.damageCount_), damageCap_(other.damageCap_) {
        // Deep copy service history
        serviceHistory_ = (serviceCap_ > 0) ? new ServiceRecord[serviceCap_] : nullptr;
        for (size_t i = 0; i < serviceCount_; i++) serviceHistory_[i] = other.serviceHistory_[i];

        // Deep copy damage codes
        damageCodes_ = (damageCap_ > 0) ? new int[damageCap_] : nullptr;
        for (size_t i = 0; i < damageCount_; i++) damageCodes_[i] = other.damageCodes_[i];

        totalCars_++;
    }
   ///Destructor
    ~Car() {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        totalCars_--;
    }
  // Assignment Operator
    Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }
   // Friend Swap Function- to swap all non-static members
    friend void swap(Car& lhs, Car& rhs) noexcept {
        using std::swap;
        swap(lhs.vin_, rhs.vin_);
        swap(lhs.make_, rhs.make_);
        swap(lhs.model_, rhs.model_);
        swap(lhs.price_, rhs.price_);
        swap(lhs.serviceHistory_, rhs.serviceHistory_);
        swap(lhs.serviceCount_, rhs.serviceCount_);
        swap(lhs.serviceCap_, rhs.serviceCap_);
        swap(lhs.damageCodes_, rhs.damageCodes_);
        swap(lhs.damageCount_, rhs.damageCount_);
        swap(lhs.damageCap_, rhs.damageCap_);
    }

    // Static accessor
    static size_t getTotalCars() { return totalCars_; }

    // Setters
    void setVIN(const std::string& vin) { vin_ = vin; }
    void setMake(const std::string& make) { make_ = make; }
    void setModel(const std::string& model) { model_ = model; }
    void setPrice(double price) {
        if (price < 0) throw std::invalid_argument("Price cannot be negative");
        price_ = price;
    }

    // Getters
    const std::string& getVIN() const { return vin_; }
    const std::string& getMake() const { return make_; }
    const std::string& getModel() const { return model_; }
    double getPrice() const { return price_; }
    size_t getServiceCount() const { return serviceCount_; }
    size_t getDamageCount() const { return damageCount_; }
    const ServiceRecord* getServiceHistory() const { return serviceHistory_; }
    const int* getDamageCodes() const { return damageCodes_; }

    // Business logic
    void addService(const ServiceRecord& rec) {
        if (serviceCount_ == serviceCap_) reserveService(serviceCap_ == 0 ? 2 : serviceCap_ * 2);
        serviceHistory_[serviceCount_++] = rec;
    }

    void addDamageCode(int code) {
        if (damageCount_ == damageCap_) reserveDamage(damageCap_ == 0 ? 2 : damageCap_ * 2);
        damageCodes_[damageCount_++] = code;
    }
  // printInfo- to print the values in a readable format text
    void printInfo() const {
        std::cout << "VIN: " << vin_ << " | " << make_ << " " << model_
                  << " | $" << price_ << std::endl;
        std::cout << " Services: " << serviceCount_ << " | Damages: " << damageCount_ << std::endl;
        for (size_t i = 0; i < serviceCount_; i++) serviceHistory_[i].print();
        std::cout << " Damage codes: ";
        for (size_t i = 0; i < damageCount_; i++) std::cout << damageCodes_[i] << " ";
        std::cout << std::endl;
    }

    // Helpers functions
    void printDamageCodes() const {
        for (size_t i = 0; i < damageCount_; i++) std::cout << damageCodes_[i] << " ";
        std::cout << std::endl;
    }
    void modifyDamageCode(size_t idx, int newCode) {
        if (idx < damageCount_) damageCodes_[idx] = newCode;
    }
     void reserveService(size_t newCap) {
        if (newCap <= serviceCap_) return;
        ServiceRecord* newArr = new ServiceRecord[newCap];
        for (size_t i = 0; i < serviceCount_; i++) newArr[i] = serviceHistory_[i];
        delete[] serviceHistory_;
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }
    void reserveDamage(size_t newCap) {
        if (newCap <= damageCap_) return;
        int* newArr = new int[newCap];
        for (size_t i = 0; i < damageCount_; i++) newArr[i] = damageCodes_[i];
        delete[] damageCodes_;
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }

};

size_t Car::totalCars_ = 0;

// Global Functions
double averagePrice(const Car* arr, size_t n) {
    if (n == 0) return 0;
    double sum = 0;
    for (size_t i = 0; i < n; i++) sum += arr[i].getPrice();
    return sum / n;
}
bool compareByPriceAsc(const Car& a, const Car& b) { return a.getPrice() < b.getPrice(); }
bool compareByPriceDesc(const Car& a, const Car& b) { return a.getPrice() > b.getPrice(); }
bool areCarsEqual(const Car& a, const Car& b) { return a.getVIN() == b.getVIN(); }
const Car* maxPriceCar(const Car* arr, size_t n) {
    if (n == 0) return nullptr;
    const Car* maxC = &arr[0];
    for (size_t i = 1; i < n; i++) if (arr[i].getPrice() > maxC->getPrice()) maxC = &arr[i];
    return maxC;
}
const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin) {
    for (size_t i = 0; i < n; i++) if (arr[i].getVIN() == vin) return &arr[i];
    return nullptr;
}
size_t countCarsWithDamage(const Car* arr, size_t n, int code) {
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        const int* d = arr[i].getDamageCodes();
        for (size_t j = 0; j < arr[i].getDamageCount(); j++) if (d[j] == code) { count++; break; }
    }
    return count;
}
void swapCars(Car& a, Car& b) { swap(a, b); }

// Main Function
int main() {
    std::cout << "Counter = " << Car::getTotalCars() << std::endl;

    Car cDefault;
    std::cout << "\n-- Default constructed car --" << std::endl;
    cDefault.printInfo();

    Car cHonda("1HGCM", "Honda", "Accord", 19999.99);
    Car cAcura("JH4KA", "Acura", "TLX", 27999.49);
    Car cTesla("5YJ3E", "Tesla", "Model 3", 39999.00);
    Car cBMW("WBA4", "BMW", "3 Series", 34999.99);
    Car cFord("1FA6P", "Ford", "Mustang", 31200.00);

    int damageHonda[] = {101, 205, 307};
    int damageAcura[] = {102, 208};
    int damageTesla[] = {110, 220, 330, 440};
    int damageBMW[]   = {150, 250};
    int damageFord[]  = {175, 285, 395, 505, 615};

    for (int d : damageHonda) cHonda.addDamageCode(d);
    for (int d : damageAcura) cAcura.addDamageCode(d);
    for (int d : damageTesla) cTesla.addDamageCode(d);
    for (int d : damageBMW)   cBMW.addDamageCode(d);
    for (int d : damageFord)  cFord.addDamageCode(d);

    ServiceRecord srOilChange("2022-03-15", 15000, "Oil change");
    ServiceRecord srBrakeReplace("2023-01-10", 25000, "Brake pads replacement");
    ServiceRecord srTireRotate("2023-06-20", 30000, "Tire rotation");
    ServiceRecord srInspection("2024-02-05", 35000, "Annual safety inspection");

    cHonda.addService(srOilChange);
    cHonda.addService(srBrakeReplace);
    cTesla.addService(srTireRotate);
    cTesla.addService(srInspection);

    Car cTeslaCopy(cTesla);
    std::cout << "\n-- Tesla copy constructed --" << std::endl;
    cTeslaCopy.printInfo();

    std::cout << "\nDamage codes before modification:" << std::endl;
    std::cout << "Original Tesla: "; cTesla.printDamageCodes();
    std::cout << "Copy Tesla: ";     cTeslaCopy.printDamageCodes();

    cTeslaCopy.modifyDamageCode(0, 999);
    std::cout << "After modifying copy:" << std::endl;
    std::cout << "Original Tesla: "; cTesla.printDamageCodes();
    std::cout << "Copy Tesla: ";     cTeslaCopy.printDamageCodes();

    std::cout << "\nService count (Tesla) = " << cTesla.getServiceCount()
              << ", (TeslaCopy) = " << cTeslaCopy.getServiceCount() << std::endl;

    Car cBMWAssign;
    cBMWAssign = cBMW;
    std::cout << "\n-- BMW assigned to new object --" << std::endl;
    cBMWAssign.printInfo();

    cBMWAssign.modifyDamageCode(1, 888);
    std::cout << "Original BMW: "; cBMW.printDamageCodes();
    std::cout << "Assigned BMW: "; cBMWAssign.printDamageCodes();

    int N = 3;
    Car* garage = new Car[N];
    garage[0] = cHonda;
    garage[1] = cAcura;
    garage[2] = cTesla;

    std::cout << "\n-- Garage Cars --" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "\nCar #" << i + 1 << std::endl;
        garage[i].printInfo();
    }

    std::cout << "\nAverage price: " << averagePrice(garage, N) << std::endl;

    std::cout << "Max price car VIN: " << maxPriceCar(garage, N)->getVIN() << std::endl;

    const Car* found = findCarByVIN(garage, N, "JH4KA");
    if (found) std::cout << "Found Acura TLX, price = " << found->getPrice() << std::endl;

    std::cout << "Cars with damage 220: " << countCarsWithDamage(garage, N, 220) << std::endl;
    std::cout << "Are garage[0] and garage[2] equal? "
              << (areCarsEqual(garage[0], garage[2]) ? "Yes" : "No") << std::endl;

    delete[] garage;
    std::cout << "\nGarage deleted." << std::endl;

    const Car cConst("CONSTVIN", "Lexus", "IS", 40000);
    // cConst.addDamageCode(123); // Uncomment to test const correctness → compile error

    std::cout << "\nFinal totalCars = " << Car::getTotalCars() << std::endl;
    return 0;
}
