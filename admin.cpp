#include <iostream>
#include <string>
#include <map>

using namespace std;

// Define a structure to represent user accounts
struct User {
    string username;
    string password;
    string role;
};

// Function to check if a username and password are valid
bool isValidUser(map<string, User>& users, string username, string password) {
    if (users.find(username) != users.end()) {
        User user = users[username];
        return user.password == password;
    }
    return false;
}

int main() {
    // Create a map to store user accounts
    map<string, User> users;

    // Add some sample users
    users["admin"] = { "admin", "admin123", "Admin" };
    users["staff"] = { "staff", "staff123", "Staff" };
    users["student"] = { "student", "student123", "Student" };

    // User input
    string username, password;

    // Main login loop
    while (true) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (isValidUser(users, username, password)) {
            User user = users[username];
            cout << "Login successful! Welcome, " << user.role << "." << endl;
            break;
        } else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    }

    return 0;
}
