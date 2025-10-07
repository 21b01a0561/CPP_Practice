#include "divyaSree_oct1_task4_StudentSystem.h"

// ================= Base Student =================
Student::Student(const std::string& n, const std::string& id, const std::string& dept)
    : name(n), studentID(id), department(dept) {}

std::string Student::getName() const { return name; }
std::string Student::getID() const { return studentID; }
std::string Student::getDepartment() const { return department; }
std::string Student::getLevel() const { return "Student"; }

// ================= Undergraduate =================
UndergraduateStudent::UndergraduateStudent(const std::string& n, const std::string& id,
                                           const std::string& dept, int y, int credits)
    : Student(n, id, dept), year(y), creditsEarned(credits) {}

int UndergraduateStudent::getYear() const { return year; }
int UndergraduateStudent::getCreditsEarned() const { return creditsEarned; }
std::string UndergraduateStudent::getLevel() const { return "UndergraduateStudent"; }

Freshman::Freshman(const std::string& n, const std::string& id,
                   const std::string& dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
std::string Freshman::getLevel() const { return "Freshman"; }

Sophomore::Sophomore(const std::string& n, const std::string& id,
                     const std::string& dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
std::string Sophomore::getLevel() const { return "Sophomore"; }

Junior::Junior(const std::string& n, const std::string& id,
               const std::string& dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
std::string Junior::getLevel() const { return "Junior"; }

Senior::Senior(const std::string& n, const std::string& id,
               const std::string& dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
std::string Senior::getLevel() const { return "Senior"; }

HonorsSenior::HonorsSenior(const std::string& n, const std::string& id,
                           const std::string& dept, int y, int credits,
                           const std::string& thesis)
    : Senior(n, id, dept, y, credits), thesisTitle(thesis) {}
std::string HonorsSenior::getThesisTitle() const { return thesisTitle; }
std::string HonorsSenior::getLevel() const { return "HonorsSenior"; }

ExchangeSenior::ExchangeSenior(const std::string& n, const std::string& id,
                               const std::string& dept, int y, int credits,
                               const std::string& homeUni)
    : Senior(n, id, dept, y, credits), homeUniversity(homeUni) {}
std::string ExchangeSenior::getHomeUniversity() const { return homeUniversity; }
std::string ExchangeSenior::getLevel() const { return "ExchangeSenior"; }

// ================= Graduate =================
GraduateStudent::GraduateStudent(const std::string& n, const std::string& id,
                                 const std::string& dept, const std::string& adv)
    : Student(n, id, dept), advisor(adv) {}
std::string GraduateStudent::getAdvisor() const { return advisor; }
std::string GraduateStudent::getLevel() const { return "GraduateStudent"; }

MastersStudent::MastersStudent(const std::string& n, const std::string& id,
                               const std::string& dept, const std::string& adv)
    : GraduateStudent(n, id, dept, adv) {}
std::string MastersStudent::getLevel() const { return "MastersStudent"; }

ThesisMastersStudent::ThesisMastersStudent(const std::string& n, const std::string& id,
                                           const std::string& dept, const std::string& adv,
                                           const std::string& thesis)
    : MastersStudent(n, id, dept, adv), thesisTitle(thesis) {}
std::string ThesisMastersStudent::getThesisTitle() const { return thesisTitle; }
std::string ThesisMastersStudent::getLevel() const { return "ThesisMastersStudent"; }

NonThesisMastersStudent::NonThesisMastersStudent(const std::string& n, const std::string& id,
                                                 const std::string& dept, const std::string& adv,
                                                 const std::string& project)
    : MastersStudent(n, id, dept, adv), projectTitle(project) {}
std::string NonThesisMastersStudent::getProjectTitle() const { return projectTitle; }
std::string NonThesisMastersStudent::getLevel() const { return "NonThesisMastersStudent"; }

DoctoralStudent::DoctoralStudent(const std::string& n, const std::string& id,
                                 const std::string& dept, const std::string& adv,
                                 const std::string& dissertation, int years)
    : GraduateStudent(n, id, dept, adv),
      dissertationTitle(dissertation), yearsInProgram(years) {}
std::string DoctoralStudent::getDissertationTitle() const { return dissertationTitle; }
int DoctoralStudent::getYearsInProgram() const { return yearsInProgram; }
std::string DoctoralStudent::getLevel() const { return "DoctoralStudent"; }

PhDCandidate::PhDCandidate(const std::string& n, const std::string& id,
                           const std::string& dept, const std::string& adv,
                           const std::string& dissertation, int years)
    : DoctoralStudent(n, id, dept, adv, dissertation, years) {}
std::string PhDCandidate::getLevel() const { return "PhDCandidate"; }

PostDocFellow::PostDocFellow(const std::string& n, const std::string& id,
                             const std::string& dept, const std::string& adv,
                             const std::string& grant)
    : GraduateStudent(n, id, dept, adv), researchGrant(grant) {}
std::string PostDocFellow::getResearchGrant() const { return researchGrant; }
std::string PostDocFellow::getLevel() const { return "PostDocFellow"; }

