// main.cpp
// Test program for composition-based BasePlusCommissionEmployee

#include "DivyaSree_oct6_task1_BasePlusCommissionEmployee.h"
#include "DivyaSree_oct6_task1_CommissionEmployee.h"

int main() {
    {
        // CommissionEmployee object (will invoke constructor & destructor)
        const CommissionEmployee employee1("Bob", "Lewis", "333-33-3333", 5000, .04);
    }

    {
        // BasePlusCommissionEmployee object (composition)
        const BasePlusCommissionEmployee employee2("Lisa", "Jones", "555-55-5555", 2000, .06, 800);
    }

    {
        // Another BasePlusCommissionEmployee object
        const BasePlusCommissionEmployee employee3("Mark", "Sands", "888-88-8888", 8000, .15, 2000);
    }

    return 0;
}
