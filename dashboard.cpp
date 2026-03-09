#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to hold student information
struct Student {
    string name;
    int rollNumber;
    double grade;
};

// Function to display the menu
void dashboard() {
    cout << "Student Dashboard" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<Student> students; // Vector to store student data

    while (true) {
       void dashboard();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: // Add Student
                {
                    Student student;
                    cout << "Enter student name: ";
                    cin.ignore();
                    getline(cin, student.name);
                    cout << "Enter student roll number: ";
                    cin >> student.rollNumber;
                    cout << "Enter student grade: ";
                    cin >> student.grade;

                    students.push_back(student);
                    cout << "Student added successfully!" << endl;
                }
                break;

            case 2: // View All Students
                if (students.empty()) {
                    cout << "No students to display." << endl;
                } else {
                    cout << "Student List:" << endl;
                    for (const Student& student : students) {
                        cout << "Name: " << student.name << "\t";
                        cout << "Roll Number: " << student.rollNumber << "\t";
                        cout << "Grade: " << student.grade << endl;
                    }
                }
                break;

            case 3: // Search Student
                {
                    int rollNumber;
                    cout << "Enter student roll number to search: ";
                    cin >> rollNumber;

                    bool found = false;
                    for (const Student& student : students) {
                        if (student.rollNumber == rollNumber) {
                            cout << "Student found:" << endl;
                            cout << "Name: " << student.name << "\t";
                            cout << "Roll Number: " << student.rollNumber << "\t";
                            cout << "Grade: " << student.grade << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Student not found." << endl;
                    }
                }
                break;

            case 4: // Exit
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
