#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value = 0, Node* next = nullptr) : data(value), next(next) {}
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node* createList(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* insatfirst(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* specificposition(Node* head, int value, int position) {
    if (position <= 0) {
        std::cout << "Invalid position" << std::endl;
        return head;
    }
    if (position == 1 || head == nullptr) {
        return insatfirst(head, value);
    }
    Node* newNode = createNode(value);
    Node* current = head;
    for (int i = 1; i < position - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* delete1(Node* head) {
    if (head == nullptr) {
        std::cout << "List is already empty" << std::endl;
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deletespecific(Node* head, int position) {
    if (head == nullptr) {
        std::cout << "List is already empty" << std::endl;
        return head;
    }
    if (position <= 0) {
        std::cout << "Invalid position" << std::endl;
        return head;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        std::cout << "Invalid position" << std::endl;
        return head;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

Node* deletelast(Node* head) {
    if (head == nullptr) {
        std::cout << "List is already empty" << std::endl;
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

bool search(Node* head, int data1) {
    Node* current = head;
    int position = 1;
    bool found = false;
    while (current != nullptr) {
        if (current->data == data1) {
            std::cout << "Element " << data1 << " found at position " << position << std::endl;
            found = true;
        }
        current = current->next;
        position++;
    }
    if (!found) {
        std::cout << "Element " << data1 << " not found" << std::endl;
    }
    return found;
}

int main() {
    Node* head = nullptr;
    int limit;
    std::cout << "Enter the limit of elements in the linked list: ";
    std::cin >> limit;

    for (int i = 0; i < limit; i++) {
        int value;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> value;
        head = createList(head, value);
    }

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insertion at the beginning\n";
        std::cout << "2. Insertion at a specific position\n";
        std::cout << "3. Deletion at the beginning\n";
        std::cout << "4. Deletion at a specific position\n";
        std::cout << "5. Deletion at the end\n";
        std::cout << "6. Search for an element\n";
        std::cout << "7. Display the linked list\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int newValue;
                std::cout << "Enter the value to insert at the beginning: ";
                std::cin >> newValue;
                head = insatfirst(head, newValue);
                displayList(head);
                break;
            case 2:
                int newElt, position;
                std::cout << "Enter the value to insert: ";
                std::cin >> newElt;
                std::cout << "Enter the position to insert at: ";
                std::cin >> position;
                head = specificposition(head, newElt, position);
                displayList(head);
                break;
            case 3:
                std::cout << "Before deletion: ";
                displayList(head);
                head = delete1(head);
                std::cout << "After deletion: ";
                displayList(head);
                break;
            case 4:
                int pos;
                std::cout << "Enter the position to delete from: ";
                std::cin >> pos;
                std::cout << "Before deletion: ";
                displayList(head);
                head = deletespecific(head, pos);
                std::cout << "After deletion: ";
                displayList(head);
                break;
            case 5:
                std::cout << "Before deletion: ";
                displayList(head);
                head = deletelast(head);
                std::cout << "After deletion: ";
                displayList(head);
                break;
            case 6:
                int searchData;
                std::cout << "Enter the element to search for: ";
                std::cin >> searchData;
                search(head, searchData);
                break;
            case 7:
                std::cout << "Linked list elements: ";
                displayList(head);
                break;
            case 8:
                std::cout << "Exiting...";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 8);

    // Clean up the allocated memory
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}