#include <iostream>

const int MAX_SIZE = 100; 

int queue[MAX_SIZE];
int front = -1; 
int rear = -1;  
int oddCount = 0;
int evenCount = 0;

bool isFull() {
    return (rear == MAX_SIZE - 1);
}

bool isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int value) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    if (value % 2 == 0) {
        evenCount++;
    } else {
        oddCount++;
    }
}

void dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }

    int dequeuedValue = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1; 
    }

    if (dequeuedValue % 2 == 0) {
        evenCount--;
    } else {
        oddCount--;
    }
}

void display() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl;
}

int search(int value) {
    if (isEmpty()) {
        return -1;
    }

    for (int i = front; i <= rear; i++) {
        if (queue[i] == value) {
            return i - front;
        }
    }

    return -1;
}

void enqueueMultiple() {
    int count;
    std::cout << "How many elements you want to enqueue: ";
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        int value;
        std::cout << "Element " << (i + 1) << " = ";
        std::cin >> value;
        enqueue(value);
    }

    std::cout << "\nElements were successfully recorded." << std::endl;
}

int main() {
    int choice, value, position;
    
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
                for (int i = front; i <= rear; i++) {
                    if (queue[i] % 2 != 0) {
                        std::cout << queue[i] << " ";
                    }
                }
                std::cout << "\nEven numbers: ";
                for (int i = front; i <= rear; i++) {
                    if (queue[i] % 2 == 0) {
                        std::cout << queue[i] << " ";
                    }
                }
                std::cout << "\nTotal odd numbers: " << oddCount << "\nTotal even numbers: " << evenCount << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}