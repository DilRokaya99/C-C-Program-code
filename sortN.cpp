#include <iostream>
#include <algorithm>

int main() {
    int n;

    // Input the number of elements
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Check for valid input
    if (n <= 0) {
        std::cout << "Invalid input. Please enter a positive number of elements." << std::endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input the elements
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Sort the array using std::sort
    std::sort(arr, arr + n);

    // Display the sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate the dynamically allocated memory
    delete[] arr;

    return 0;
}
