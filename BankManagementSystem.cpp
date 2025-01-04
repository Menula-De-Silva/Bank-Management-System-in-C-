#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account Created Successfully!\n";
    }

    void showAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited Successfully!\n";
        } else {
            cout << "Invalid Deposit Amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance or Invalid Amount!\n";
        }
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
};

void saveAccountToFile(const BankAccount &account, const string &filename) {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << account.getAccountNumber() << "\n"
                << account.getBalance() << "\n";
        outFile.close();
        cout << "Account details saved to file.\n";
    } else {
        cout << "Error: Unable to save account details.\n";
    }
}

void displayMenu() {
    cout << "\nBank Management System\n";
    cout << "1. Create Account\n";
    cout << "2. Show Account\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    BankAccount account;
    bool isRunning = true;
    string filename = "accounts.txt";

    while (isRunning) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            account.createAccount();
            saveAccountToFile(account, filename);
            break;
        case 2:
            account.showAccount();
            break;
        case 3: {
            double depositAmount;
            cout << "Enter Deposit Amount: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        }
        case 4: {
            double withdrawAmount;
            cout << "Enter Withdrawal Amount: ";
            cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
            break;
        }
        case 5:
            isRunning = false;
            cout << "Thank you for using the Bank Management System. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
