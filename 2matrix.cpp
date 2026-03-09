#include <iostream>

const int MAX_SIZE = 100;

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int numRows, numCols;

    // Input matrix dimensions
    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;
    std::cout << "Enter the number of columns: ";
    std::cin >> numCols;

    if (numRows <= 0 || numCols <= 0 || numRows > MAX_SIZE || numCols > MAX_SIZE) {
        std::cout << "Invalid matrix dimensions." << std::endl;
        return 1;
    }

    // Input matrix elements
    std::cout << "Enter the matrix elements row by row:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << "Enter element at row " << i + 1 << " and column " << j + 1 << ": ";
            std::cin >> matrix[i][j];
        }
    }

    // Calculate and display sum of each row
    std::cout << "Sum of each row:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < numCols; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Row " << i + 1 << ": " << rowSum << std::endl;
    }

    // Calculate and display sum of each column
    std::cout << "Sum of each column:" << std::endl;
    for (int j = 0; j < numCols; ++j) {
        int colSum = 0;
        for (int i = 0; i < numRows; ++i) {
            colSum += matrix[i][j];
        }
        std::cout << "Column " << j + 1 << ": " << colSum << std::endl;
    }

    // Calculate and display the total sum of all elements
    int totalSum = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            totalSum += matrix[i][j];
        }
    }
    std::cout << "Total sum of all elements: " << totalSum << std::endl;

    return 0;
}
