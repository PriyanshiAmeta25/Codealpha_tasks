#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string customerName;
    int accountNumber;
    double balance;
    vector<string> transactions;

public:
    void createAccount() {
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, customerName);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        transactions.push_back("Account created with balance: " + to_string(balance));

        cout << "\nAccount created successfully!\n";
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposited: " + to_string(amount));
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance && amount > 0) {
            balance -= amount;
            transactions.push_back("Withdrawn: " + to_string(amount));
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void transfer() {
        double amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount <= balance && amount > 0) {
            balance -= amount;
            transactions.push_back("Transferred: " + to_string(amount));
            cout << "Fund transfer successful!\n";
        } else {
            cout << "Transfer failed!\n";
        }
    }

    void showDetails() {
        cout << "\n----- Account Details -----\n";
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void showTransactions() {
        cout << "\n----- Transaction History -----\n";
        for (string t : transactions) {
            cout << t << endl;
        }
    }
};

int main() {
    BankAccount account;
    int choice;

    account.createAccount();

    do {
        cout << "\n===== Banking Menu =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer Funds\n";
        cout << "4. View Account Details\n";
        cout << "5. View Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.deposit();
                break;
            case 2:
                account.withdraw();
                break;
            case 3:
                account.transfer();
                break;
            case 4:
                account.showDetails();
                break;
            case 5:
                account.showTransactions();
                break;
            case 6:
                cout << "Thank you for using Banking System!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
