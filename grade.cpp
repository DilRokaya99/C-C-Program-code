#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int marks;
    char grade;

public:
    // Constructor to initialize the data members
    Student(const std::string& n, int m, char g) : name(n), marks(m), grade(g) {}

    // Function to display student information
    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: " << marks << std::endl;
        std::cout << "Grade: " << grade << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
};

int main() {
    const int numStudents = 3; // You can change this to the desired number of students

    // Create an array of Student objects
    Student students[numStudents] = {
        {"Alice", 85, 'A'},
        {"Bob", 92, 'A'},
        {"Charlie", 78, 'B'}
    };

    // Display student information using a loop
    std::cout << "Student Information:" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        students[i].displayInfo();
    }

    return 0;
}
