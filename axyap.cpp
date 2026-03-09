#include <iostream>
#include <fstream>
using namespace std;

// Class for representing a bank account
class BankAccount {
public:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNum, string accHolderName, double initialBalance) {
        this->accountNumber = accNum;
        this->accountHolderName = accHolderName;
        this->balance = initialBalance;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs" << amount << " into account " << accountNumber << endl;
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn Rs" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }

    // Function to check the balance of the account
    void checkBalance() {
        cout << "Account " << accountNumber << " has a balance of Rs" << balance << endl;
    }
};

// Node class for the linked list
class Node {
public:
    BankAccount* data;
    Node* next;

    Node(BankAccount* acc) {
        data = acc;
        next = nullptr;
    }
};

// Class for representing a queue of bank accounts using linked list
class BankQueue {
private:
    Node* front;
    Node* rear;

public:
    BankQueue() {
        front = rear = nullptr;
    }

    // Function to add a new account to the queue
    void enqueue(BankAccount* acc) {
        Node* newNode = new Node(acc);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove and process the front account from the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
        } else {
            BankAccount* acc = front->data;
            front = front->next;
            cout << "Processing account " << acc->accountNumber << endl;
            processAccount(acc);
            delete acc;
        }
    }

    // Function to process account operations (deposit, withdraw, check balance)
    void processAccount(BankAccount* acc) {
        int choice;
        do {
            cout << "\n******Choose an operation for account -> " << acc->accountNumber << " :" << endl;
            cout << "1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double amount;
                    cout << "Enter the amount to deposit: Rs";
                    cin >> amount;
                    acc->deposit(amount);
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter the amount to withdraw: Rs";
                    cin >> amount;
                    acc->withdraw(amount);
                    break;
                }
                case 3:
                    acc->checkBalance();
                    break;
                case 4:
                    cout << "Exiting account " << acc->accountNumber << " operations." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }

    // Function to show all created accounts
    void showAllAccounts() {
        cout << "\n*** All Created Accounts ***" << endl;
        Node* current = front;
        while (current != nullptr) {
            BankAccount* acc = current->data;
            cout << "Account Number: " << acc->accountNumber << ", Account Holder: " << acc->accountHolderName << ", Balance: Rs" << acc->balance << endl;
            current = current->next;
        }
    }

    // Function to get the front node (for saving accounts to a file)
    Node* getFront() const {
        return front;
    }
};

// Function to save all accounts to a file
void saveAccountsToFile(const BankQueue& bankQueue) {
    ofstream outputFile("banking.txt");
    if (!outputFile) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    }

    const Node* current = bankQueue.getFront();
    while (current != nullptr) {
        BankAccount* acc = current->data;
        outputFile << acc->accountNumber << " " << acc->accountHolderName << " " << acc->balance << endl;
        current = current->next;
    }

    outputFile.close();
}

// Function to load accounts from a file
void loadAccountsFromFile(BankQueue& bankQueue) {
    ifstream inputFile("banking.txt");
    if (!inputFile) {
        cout << "No existing account data found." << endl;
        return;
    }

    while (!inputFile.eof()) {
        string accNum, accHolderName;
        double initialBalance;
        inputFile >> accNum >> accHolderName >> initialBalance;
        if (!inputFile.eof()) {
            BankAccount* acc = new BankAccount(accNum, accHolderName, initialBalance);
            bankQueue.enqueue(acc);
        }
    }

    inputFile.close();
}

int main() {
    BankQueue bankQueue;
    loadAccountsFromFile(bankQueue);

    while (true) {
        int choice;
        cout << "\n--------------------------Bank Queue Management System--------------------------" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Process Next Account" << endl;
        cout << "3. Show All Accounts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accNum, accHolderName;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter account holder's name: ";
                cin.ignore(); 
                getline(cin, accHolderName);
                cout << "Enter initial balance: Rs";
                cin >> initialBalance;
                BankAccount* acc = new BankAccount(accNum, accHolderName, initialBalance);
                bankQueue.enqueue(acc);
                saveAccountsToFile(bankQueue);
                break;
            }
            case 2:
                bankQueue.dequeue();
                break;
            case 3:
                bankQueue.showAllAccounts();
                break;
            case 4:
                cout << "Exiting the Bank Queue Management System." << endl;
               
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

 return 0;
}