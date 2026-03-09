#include <iostream>

class Rectangle {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double Area() {
        return length * breadth;
    }

    ~Rectangle() {
        std::cout << "Rectangle object destroyed." << std::endl;
    }
};

int main() {
    double length, breadth;

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;

    std::cout << "Enter the width of the rectangle: ";
    std::cin >> breadth;

    Rectangle* rectPtr = new Rectangle(length, breadth); // Create a dynamic object

    double area = rectPtr->Area();
    std::cout << "Area of the rectangle: " << area << std::endl;

    delete rectPtr; // Delete the dynamic object to free memory

    return 0;
}
