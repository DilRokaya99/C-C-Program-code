#include <iostream>

class Rectangle {
public:
    Rectangle(double length, double width) : length(length), width(width) {}

    // Public member function to calculate area
    double calculateArea() {
        return length * width;
    }

private:
    double length;
    double width;

    // Declare the global function as a friend
    friend double calculateAreaGlobal(Rectangle rect);
};

// Global function declared as a friend in the Rectangle class
double calculateAreaGlobal(Rectangle rect) {
    // Access the private data members of the Rectangle class
    return rect.length * rect.width;
}

int main() {
    Rectangle rect(5.0, 3.0);

    // Calculate the area using the public member function
    double area1 = rect.calculateArea();
    std::cout << "Area (using member function): " << area1 << std::endl;

    // Calculate the area using the global function
    double area2 = calculateAreaGlobal(rect);
    std::cout << "Area (using global function): " << area2 << std::endl;

    return 0;
}
