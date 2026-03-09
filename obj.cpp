#include <iostream>

class create {
private:
    static int objectCount; // Static member variable to keep track of the count

public:
    create() {
        objectCount++; // Increment the count when an object is created
    }

    ~create() {
        objectCount--; // Decrement the count when an object is destroyed
    }

    static int getObjectCount() {
        return objectCount; // Return the current count
    }
};

// Initialize the static member variable
int create::objectCount = 0;

int main() {
    create obj1;
    create obj2;
    create obj3;

    std::cout << "Total number of objects created: " << create::getObjectCount() << std::endl;

    return 0;
}
