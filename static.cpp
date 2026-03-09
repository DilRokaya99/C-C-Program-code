#include <iostream>

class SumCalculator {
public:
    // Constructor to initialize sum to 0
    SumCalculator() {
        sum = 0;
    }

    // Function to add a number to the sum
    static void addToSum(int num) {
        sum += num;
    }

    // Function to get the current sum
    static int getSum() {
        return sum;
    }

private:
    static int sum;
};

// Initialize the static data member outside of the class
int SumCalculator::sum = 0;

int main() {
    SumCalculator::addToSum(5);
    SumCalculator::addToSum(10);
    SumCalculator::addToSum(15);

    int totalSum = SumCalculator::getSum();

    std::cout << "Sum of numbers: " << totalSum << std::endl;

    return 0;
}
