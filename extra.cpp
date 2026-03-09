#include <iostream>
#include <string>

// Base class for Student
class Student {
protected:
    int rollno;
    std::string name;

public:
    Student(int _rollno, std::string _name) : rollno(_rollno), name(_name) {}

    void displayStudentInfo() {
        std::cout << "Roll No: " << rollno << std::endl;
        std::cout << "Name: " << name << std::endl;
    }
};

// Derived class for academic scores
class Academic : virtual public Student {
protected:
    int mathScore;
    int physicsScore;
    int chemistryScore;

public:
    Academic(int _rollno, std::string _name, int _math, int _physics, int _chemistry)
        : Student(_rollno, _name), mathScore(_math), physicsScore(_physics), chemistryScore(_chemistry) {}

    void displayAcademicInfo() {
        std::cout << "Math Score: " << mathScore << std::endl;
        std::cout << "Physics Score: " << physicsScore << std::endl;
        std::cout << "Chemistry Score: " << chemistryScore << std::endl;
    }
};

// Derived class for sports scores
class Sports : virtual public Student {
protected:
    int sportsScore;

public:
    Sports(int _rollno, std::string _name, int _sportsScore)
        : Student(_rollno, _name), sportsScore(_sportsScore) {}

    void displaySportsInfo() {
        std::cout << "Sports Score: " << sportsScore << std::endl;
    }
};

// Derived class for final result (inherits from Academic and Sports)
class Result : public Academic, public Sports {
public:
    Result(int _rollno, std::string _name, int _math, int _physics, int _chemistry, int _sportsScore)
        : Student(_rollno, _name), Academic(_rollno, _name, _math, _physics, _chemistry), Sports(_rollno, _name, _sportsScore) {}

    void displayFinalResult() {
        std::cout << "\nFinal Result for " << name << " (Roll No: " << rollno << "):" << std::endl;
        displayAcademicInfo();
        displaySportsInfo();
    }
};

int main() {
    int rollno, math, physics, chemistry, sportsScore;
    std::string name;

    std::cout << "Enter Student Roll No: ";
    std::cin >> rollno;
    std::cout << "Enter Student Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter Math Score: ";
    std::cin >> math;
    std::cout << "Enter Physics Score: ";
    std::cin >> physics;
    std::cout << "Enter Chemistry Score: ";
    std::cin >> chemistry;
    std::cout << "Enter Sports Score: ";
    std::cin >> sportsScore;

    Result studentResult(rollno, name, math, physics, chemistry, sportsScore);
    studentResult.displayFinalResult();

    return 0;
}
