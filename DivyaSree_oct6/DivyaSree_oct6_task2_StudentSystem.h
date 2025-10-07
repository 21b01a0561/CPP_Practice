#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include <iostream>
#include <string>

// ================= Base Class =================
class Student {
protected:
    std::string name;
    std::string studentID;
    std::string department;
public:
    Student(const std::string& n, const std::string& id, const std::string& dept);

    // Accessors
    std::string getName() const;
    std::string getID() const;
    std::string getDepartment() const;

    // Polymorphic method
    virtual std::string getLevel() const;
    virtual ~Student() {}
};

// ================= Undergraduate =================
class UndergraduateStudent : public Student {
protected:
    int year;
    int creditsEarned;
public:
    UndergraduateStudent(const std::string& n, const std::string& id,
                         const std::string& dept, int y, int credits);

    // Accessors
    int getYear() const;
    int getCreditsEarned() const;

    std::string getLevel() const override;
};

class Freshman : public UndergraduateStudent {
public:
    Freshman(const std::string& n, const std::string& id, const std::string& dept,
             int y, int credits);
    std::string getLevel() const override;
};

class Sophomore : public UndergraduateStudent {
public:
    Sophomore(const std::string& n, const std::string& id, const std::string& dept,
              int y, int credits);
    std::string getLevel() const override;
};

class Junior : public UndergraduateStudent {
public:
    Junior(const std::string& n, const std::string& id, const std::string& dept,
           int y, int credits);
    std::string getLevel() const override;
};

class Senior : public UndergraduateStudent {
public:
    Senior(const std::string& n, const std::string& id, const std::string& dept,
           int y, int credits);
    std::string getLevel() const override;
};

class HonorsSenior : public Senior {
    std::string thesisTitle;
public:
    HonorsSenior(const std::string& n, const std::string& id, const std::string& dept,
                 int y, int credits, const std::string& thesis);
    std::string getThesisTitle() const;
    std::string getLevel() const override;
};

class ExchangeSenior : public Senior {
    std::string homeUniversity;
public:
    ExchangeSenior(const std::string& n, const std::string& id, const std::string& dept,
                   int y, int credits, const std::string& homeUni);
    std::string getHomeUniversity() const;
    std::string getLevel() const override;
};

// ================= Graduate =================
class GraduateStudent : public Student {
protected:
    std::string advisor;
public:
    GraduateStudent(const std::string& n, const std::string& id,
                    const std::string& dept, const std::string& adv);

    std::string getAdvisor() const;
    std::string getLevel() const override;
};

class MastersStudent : public GraduateStudent {
public:
    MastersStudent(const std::string& n, const std::string& id,
                   const std::string& dept, const std::string& adv);
    std::string getLevel() const override;
};

class ThesisMastersStudent : public MastersStudent {
    std::string thesisTitle;
public:
    ThesisMastersStudent(const std::string& n, const std::string& id,
                         const std::string& dept, const std::string& adv,
                         const std::string& thesis);
    std::string getThesisTitle() const;
    std::string getLevel() const override;
};

class NonThesisMastersStudent : public MastersStudent {
    std::string projectTitle;
public:
    NonThesisMastersStudent(const std::string& n, const std::string& id,
                            const std::string& dept, const std::string& adv,
                            const std::string& project);
    std::string getProjectTitle() const;
    std::string getLevel() const override;
};

class DoctoralStudent : public GraduateStudent {
protected:
    std::string dissertationTitle;
    int yearsInProgram;
public:
    DoctoralStudent(const std::string& n, const std::string& id,
                    const std::string& dept, const std::string& adv,
                    const std::string& dissertation, int years);
    std::string getDissertationTitle() const;
    int getYearsInProgram() const;
    std::string getLevel() const override;
};

class PhDCandidate : public DoctoralStudent {
public:
    PhDCandidate(const std::string& n, const std::string& id, const std::string& dept,
                 const std::string& adv, const std::string& dissertation, int years);
    std::string getLevel() const override;
};

class PostDocFellow : public GraduateStudent {
    std::string researchGrant;
public:
    PostDocFellow(const std::string& n, const std::string& id, const std::string& dept,
                  const std::string& adv, const std::string& grant);
    std::string getResearchGrant() const;
    std::string getLevel() const override;
};

#endif
