#include <iostream>
#include <vector>
#include <string>
#include<map>
#include<fstream>
// Define a Student class to store student information

class Student {
public:
    std::string name,username,password;
    int rollNumber;
    std::string roomNumber;

    // Constructor
    Student(std::string _name, int _rollNumber, std::string _roomNumber)
        : name(_name), rollNumber(_rollNumber), roomNumber(_roomNumber) {}
};

// Define a HostelManager class to manage students
class HostelManager {
private:
    std::vector<Student> students;

public:
    // Function to register a new student
    void registerStudent(std::string name, int rollNumber, std::string roomNumber) {
        Student newStudent(name, rollNumber, roomNumber);
        students.push_back(newStudent);
        std::cout << "Student " << name << " registered successfully!" << std::endl;
    }

    // Function to list all registered students
    void listStudents() {
        if (students.empty()) {
            std::cout << "No students registered yet." << std::endl;
        } else {
            std::cout << "List of registered students:" << std::endl;
            for (const Student& student : students) {
                std::cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Room Number: " << student.roomNumber << std::endl;
            }
        }
    }
};
int main() {
    HostelManager manager;
    // Menu-driven interface
    while (true) {
        std::cout << "\t\t....Hostel Management System...." << std::endl;
        std::cout<<"1.student management system"<<std::endl;
        std::cout<<"2.student admin"<<std::endl;
        std::cout<<"3.student dashboard"<<std::endl;
        std::cout << "1. Register Student" << std::endl;
        std::cout << "2. List Students" << std::endl;
        std::cout << "3. Exit" << std::endl;
        int choice;
        std::cout<<"enter any your choice:";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, roomNumber;
                int rollNumber;
                std::cout << "Enter Student Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter Roll Number: ";
                std::cin >> rollNumber;
                std::cout << "Enter Room Number: ";
                std::cin >> roomNumber;
                manager.registerStudent(name, rollNumber, roomNumber);
                break;
            }
            case 2:
                manager.listStudents();
                break;
         case 3:
 case 4:
 std::cout << "Exiting program." << std::endl;
 default:
 std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
    }