#include <iostream>

int sum(int a, int n) {
    int sum = 0;

    for (int i = a; i < a + n; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    int a, n;

    std::cout << "Enter the starting integer (a): ";
    std::cin >> a;

    std::cout << "Enter the number of consecutive integers (n): ";
    std::cin >> n;

    int result = sum(a, n);

    std::cout << "Sum of " << n << " consecutive integers starting with " << a << " = " << result << std::endl;

    return 0;
}
