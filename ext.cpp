#include <iostream>
#include <string>

class Employee {
protected:
    int emp_no;
    std::string emp_name;
    std::string emp_designation;

public:
    Employee(int no, std::string name, std::string designation)
         {
            emp_no=no;
            emp_name=name;
            emp_designation=designation;
         }

    void acceptEmployeeData() {
        std::cout << "Enter Employee Number: ";
        std::cin >> emp_no;
        std::cout << "Enter Employee Name: ";
        std::cin.ignore();
        std::getline(std::cin, emp_name);
        std::cout << "Enter Employee Designation: ";
        std::cin >> emp_designation;
    }

    void displayEmployeeData() {
        std::cout << "Employee Number: " << emp_no << std::endl;
        std::cout << "Employee Name: " << emp_name << std::endl;
        std::cout << "Employee Designation: " << emp_designation << std::endl;
    }
};

class Salary : public Employee {
private:
    double basic;
    double hra;
    double da;
    double gross_sal;

public:
    Salary(int _emp_no, std::string _emp_name, std::string _emp_designation, double _basic, double _hra, double _da)
        : Employee(_emp_no, _emp_name, _emp_designation), basic(_basic), hra(_hra), da(_da) {
        calculateGrossSalary();
    }

    void acceptSalaryData() {
        std::cout << "Enter Basic Salary: ";
        std::cin >> basic;
        std::cout << "Enter HRA: ";
        std::cin >> hra;
        std::cout << "Enter DA: ";
        std::cin >> da;
        calculateGrossSalary();
    }

    void calculateGrossSalary() {
        gross_sal = basic + hra + da;
    }

    void displaySalaryData() {
        std::cout << "Basic Salary: " << basic << std::endl;
        std::cout << "HRA: " << hra << std::endl;
        std::cout << "DA: " << da << std::endl;
        std::cout << "Gross Salary: " << gross_sal << std::endl;
    }
};

int main() {
    int emp_no;
    std::string emp_name, emp_designation;
    double basic, hra, da;

    Salary employee(0, "", "", 0.0, 0.0, 0.0); // Default values

    std::cout << "Enter Employee Data:" << std::endl;
    employee.acceptEmployeeData();

    std::cout << "Enter Salary Data:" << std::endl;
    employee.acceptSalaryData();

    std::cout << "\nEmployee Details:" << std::endl;
    employee.displayEmployeeData();
    std::cout << "\nSalary Details:" << std::endl;
    employee.displaySalaryData();

    return 0;
}
