#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape code for clearing the screen.
}
struct Book {
    int bn;
    char title[200];
    char sub[50];
    float price;
    int nob;
    char author[100];
    char publisher[30];
};

void insertData();
void displayData();
void updateData(int);
void deleteData(int);
void searchData();
int checkbkno();

int main() {
    int choice;
    int bn;

    while (true) {
      
        cout << "\n\t############################################";
        cout << "\n\t WELCOME TO THE LIBRARY BOOKS INFO SYSTEM";
        cout << "\n\t############################################";
        cout << "\n\t############### MENU #######################";
        cout << "\n\t 1. Insert Record";
        cout << "\n\t 2. Display Record";
        cout << "\n\t 3. Update Record";
        cout << "\n\t 4. Delete Record";
        cout << "\n\t 5. Search Record";
        cout << "\n\t 6. Exit";
        cout << "\n\n Enter your choice (1 to 6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertData();
                break;
            case 2:
                displayData();
                break;
            case 3:
                cout << "Enter the book number to update: ";
                cin >> bn;
                updateData(bn);
                break;
            case 4:
                cout << "Enter the book number to delete: ";
                cin >> bn;
                deleteData(bn);
                break;
            case 5:
                searchData();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}


void insertData() {
    
}

void displayData() {
    
}

void updateData(int bn) {
    
}

void deleteData(int bn) {
    
}

void searchData() {
    
}

int checkbkno() {
    
    return 0;
}
