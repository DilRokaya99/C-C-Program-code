#include <iostream>

class Base {
public:
    virtual int getMarks() const {
        return 0;
    }
};

class SubjectA : public virtual Base {
protected:
    int marksA;

public:
    SubjectA(int marks) : marksA(marks) {}

    int getMarks() const override {
        return marksA;
    }
};

class SubjectB : public virtual Base {
protected:
    int marksB;

public:
    SubjectB(int marks) : marksB(marks) {}

    int getMarks() const override {
        return marksB;
    }
};

class Student : public SubjectA, public SubjectB {
public:
    Student(int marksA, int marksB) : SubjectA(marksA), SubjectB(marksB) {}

    int getTotalMarks() const {
        return SubjectA::getMarks() + SubjectB::getMarks();
    }
};


int main() {
    int marksA, marksB;
    std::cout << "Enter marks for Subject A: ";
    std::cin >> marksA;
    std::cout << "Enter marks for Subject B: ";
    std::cin >> marksB;

    Student student(marksA, marksB);
    int totalMarks = student.getTotalMarks();

    std::cout << "Total marks: " << totalMarks << std::endl;

    return 0;
}
