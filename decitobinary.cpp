#include <iostream>

void convert(int decimal) {
    if (decimal > 0) {
        convert(decimal / 2); // Recursive call with the quotient
        std::cout << decimal % 2;     // Print the remainder (binary digit)
    }
}

int main() {
    int decimal;

    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    if (decimal < 0) {
        std::cout << "Please enter a non-negative decimal number." << std::endl;
        return 1;
    }

    std::cout << "Binary representation: ";
    if (decimal == 0) {
        std::cout << "0";
    } else {
        convert(decimal);
    }

    std::cout << std::endl;

    return 0;
}
