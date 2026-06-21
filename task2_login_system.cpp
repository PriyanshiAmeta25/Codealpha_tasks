#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    bool exists = false;

    cout << "\n=== Registration ===\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Input validation
    if (username.empty() || password.empty()) {
        cout << "Username or password cannot be empty!\n";
        return;
    }

    // Check duplicate username
    ifstream readFile("users.txt");
    string storedUser, storedPass;

    while (readFile >> storedUser >> storedPass) {
        if (storedUser == username) {
            exists = true;
            break;
        }
    }
    readFile.close();

    if (exists) {
        cout << "Username already exists!\n";
        return;
    }

    // Save user
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    bool found = false;

    cout << "\n=== Login ===\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream readFile("users.txt");
    string storedUser, storedPass;

    while (readFile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }
    readFile.close();

    if (found)
        cout << "Login successful!\n";
    else
        cout << "Invalid username or password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}   
