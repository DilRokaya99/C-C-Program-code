#include <iostream>
struct Node {
    int data;
    Node* next;
};
Node* front = nullptr;
Node* rear = nullptr;
int oddCount = 0;
int evenCount = 0;
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    if (value % 2 == 0) {
        evenCount++;
    } else {
        oddCount++;
    }
}
void dequeue() {
    if (front == nullptr) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }
     Node* temp = front;
    front = front->next;

    if (temp->data % 2 == 0) {
        evenCount--;
    } else {
        oddCount--;
    }
     delete temp;
}
void display() {
    Node* current = front;
    std::cout << "Queue elements: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
int search(int value) {
    Node* current = front;
    int position = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}
void enqueueMultiple() {
    int count;
    std::cout << "How many element you want to enqueue: ";
    std::cin >> count;
    for (int i = 0; i < count; i++) {
        int value;
        std::cout << "element " << (i + 1) << "= ";
        std::cin >> value;
        enqueue(value);
    }
    std::cout<<"\n'Your element were sucessfully recorded'";
}
int main() {
    int choice, value;
    int position = 0;
    Node* current = nullptr;
    while (true) {
        std::cout << "\n\nWhat do you want to do on QUEUE:::\n"
                  << "1. Enqueue Multiple Elements\n"
                  << "2. Enqueue\n"
                  << "3. Dequeue\n"
                  << "4. Display\n"
                  << "5. Search\n"
                  << "6. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                enqueueMultiple();
                break;
            case 2:
                std::cout << "Enter element to be enqueued: ";
                std::cin >> value;
                enqueue(value);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                display();
                break;
            case 5:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                position = search(value);
                if (position != -1) {
                    std::cout << "Value found at position " << position << " from the front." << std::endl;
                } else {
                    std::cout << "Value not found in the queue." << std::endl;
                }
                break;
            case 6:
                std::cout << "Odd numbers: ";
                current = front;
                while (current != nullptr) {
                    if (current->data % 2 != 0) {
                        std::cout << current->data << " ";
                    }
                    current = current->next;
                }
                std::cout << "\nEven numbers: ";
                current = front;
                while (current != nullptr) {
                    if (current->data % 2 == 0) {
                        std::cout << current->data << " ";
                    }
                    current = current->next;
                }
                std::cout << "\nTotal odd numbers: " << oddCount << "\nTotal even numbers: " << evenCount << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}