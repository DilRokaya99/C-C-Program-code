#include <iostream>
#include <string>

// Base class for Person
class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& _name, int _age) : name(_name), age(_age) {}

    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << " years" << std::endl;
    }
};

// Derived class for Student (Person is the base class)
class Student : public Person {
protected:
    int studentID;

public:
    Student(const std::string& _name, int _age, int _studentID)
        : Person(_name, _age), studentID(_studentID) {}

    void displayStudentInfo() {
        std::cout << "Student ID: " << studentID << std::endl;
        displayInfo();  // Calling the base class method
    }
};

// Derived class for Employee (Person is the base class)
class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(const std::string& _name, int _age, int _employeeID)
        : Person(_name, _age), employeeID(_employeeID) {}

    void displayEmployeeInfo() {
        std::cout << "Employee ID: " << employeeID << std::endl;
        displayInfo();  // Calling the base class method
    }
};

// Derived class for Result (Multiple inheritance from Student and Employee)
class Result : public Student, public Employee {
public:
    Result(const std::string& _name, int _age, int _studentID, int _employeeID)
        : Student(_name, _age, _studentID), Employee(_name, _age, _employeeID) {}

    void displayResult() {
        std::cout << "\nStudent Info:" << std::endl;
        displayStudentInfo();  // Accessing methods from Student class
        std::cout << "\nEmployee Info:" << std::endl;
        displayEmployeeInfo();  // Accessing methods from Employee class
    }
};

int main() {
    std::string name;
    int age, studentID, employeeID;

    std::cout << "Enter common information:" << std::endl;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "\nEnter student-specific information:" << std::endl;
    std::cout << "Student ID: ";
    std::cin >> studentID;

    std::cout << "\nEnter employee-specific information:" << std::endl;
    std::cout << "Employee ID: ";
    std::cin >> employeeID;

    Result result(name, age, studentID, employeeID);

    result.displayResult();

    return 0;
}
