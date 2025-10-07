#include "DivyaSree_oct6_task2_StudentSystem.h"
#include <vector>
#include <iostream>
#include <typeinfo>

int main() {
    // Sample Data only
    const Freshman f("Amit", "UG101", "Computer Science", 1, 15);
    const HonorsSenior hs("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis");
    const ExchangeSenior es("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano");

    const ThesisMastersStudent tm("Priya", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization");
    const NonThesisMastersStudent ntm("Raj", "GR202", "Civil", "Dr. Mehta", "Bridge Load Simulation");
    const PhDCandidate phd("Sneha", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3);
    const PostDocFellow pdf("Dr. Tanmay", "GR401", "AI Research", "Dr. Bose", "DARPA Grant");

    std::vector<const Student*> students = {&f, &hs, &es, &tm, &ntm, &phd, &pdf};

    // Display student info using getters
    for (const Student* stu : students) {
        std::cout << "Name: " << stu->getName()
                  << ", ID: " << stu->getID()
                  << ", Department: " << stu->getDepartment()
                  << ", Level: " << stu->getLevel();

        if (const UndergraduateStudent* ug = dynamic_cast<const UndergraduateStudent*>(stu)) {
            std::cout << ", Year: " << ug->getYear()
                      << ", Credits: " << ug->getCreditsEarned();
        }

        if (const HonorsSenior* hsPtr = dynamic_cast<const HonorsSenior*>(stu)) {
            std::cout << ", Thesis: " << hsPtr->getThesisTitle();
        }

        if (const ExchangeSenior* esPtr = dynamic_cast<const ExchangeSenior*>(stu)) {
            std::cout << ", Home University: " << esPtr->getHomeUniversity();
        }

        if (const ThesisMastersStudent* tmPtr = dynamic_cast<const ThesisMastersStudent*>(stu)) {
            std::cout << ", Thesis: " << tmPtr->getThesisTitle();
        }

        if (const NonThesisMastersStudent* ntmPtr = dynamic_cast<const NonThesisMastersStudent*>(stu)) {
            std::cout << ", Project: " << ntmPtr->getProjectTitle();
        }

        if (const DoctoralStudent* phdPtr = dynamic_cast<const DoctoralStudent*>(stu)) {
            std::cout << ", Dissertation: " << phdPtr->getDissertationTitle()
                      << ", Years: " << phdPtr->getYearsInProgram();
        }

        if (const PostDocFellow* pdfPtr = dynamic_cast<const PostDocFellow*>(stu)) {
            std::cout << ", Research Grant: " << pdfPtr->getResearchGrant();
        }

        std::cout << std::endl << "-------------------------" << std::endl;
    }

    return 0;
}
