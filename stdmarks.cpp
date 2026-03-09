#include <iostream>

class Student {
private:
    static int totalMarks;
    static int studentCount;
    int marks;

public:
    Student(int m) : marks(m) {
        totalMarks += marks;
        studentCount++;
    }

    static double AveragePercentage() {
        if (studentCount == 0) {
            return 0.0;
        }
        return static_cast<double>(totalMarks) / studentCount;
    }
};

int Student::totalMarks = 0;
int Student::studentCount = 0;

int main() {
    int n;
    std::cout << "Enter the number of students: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int marks;
        std::cout << "Enter marks for student " << (i + 1) << ": ";
        std::cin >> marks;

        // Create a student object with the provided marks
        Student student(marks);
    }

    double avgPercentage = Student::AveragePercentage();

    std::cout << "Average percentage of marks for " << n << " students: " << avgPercentage << "%" << std::endl;

    return 0;
}
