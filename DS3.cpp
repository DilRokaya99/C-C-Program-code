#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;
int oddCount = 0;
int evenCount = 0;

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    if (value % 2 == 0) {
        evenCount++;
    } else {
        oddCount++;
    }
}

void pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return;
    }
    
    Node* temp = top;
    top = top->next;

    if (temp->data % 2 == 0) {
        evenCount--;
    } else {
        oddCount--;
    }
    
    delete temp;
}

void display() {
    Node* current = top;
    std::cout << "Stack elements: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int search(int value) {
    Node* current = top;
    int distance = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return distance;
        }
        current = current->next;
        distance++;
    }
    return -1;
}

int main() {
    int choice, value;
    int distance = 0;
    Node* current = nullptr; // Declare outside switch
    int n;
    std::cout<<"enter no of element:";
    std::cin>>n;
    std::cout<<"\nenter datas:";
    for(int i=0;i<n;i++){
        std::cin >> value;
        push(value);
    }
    while (true) {
        std::cout << "Options:\n"
                  << "1. Push\n"
                  << "2. Pop\n"
                  << "3. Display\n"
                  << "4. Search\n"
                  << "5. show odd or even\n" 
                  << "6. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                distance = search(value); // Moved declaration inside case
                if (distance != -1) {
                    std::cout << "Value found " << distance << " position(s) from the top." << std::endl;
                } else {
                    std::cout << "Value not found in the stack." << std::endl;
                }
                break;
            case 5:
                std::cout << "Odd numbers: ";
                current = top;
                while (current != nullptr) {
                    if (current->data % 2 != 0) {
                        std::cout << current->data << " ";
                    }
                    current = current->next;
                }
                std::cout << "\nEven numbers: ";
                current = top;
                while (current != nullptr) {
                    if (current->data % 2 == 0) {
                        std::cout << current->data << " ";
                    }
                    current = current->next;
                }
                std::cout << "\nTotal odd numbers: " << oddCount << "\nTotal even numbers: " << evenCount << std::endl;
             break;
             case 6:
             return 0;
            break;            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
  return 0;
}