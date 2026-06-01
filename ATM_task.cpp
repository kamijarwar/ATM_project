#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ah_name;
    int pin;
    double balance;

public:
    BankAccount(string name, int p, double b) {
        ah_name = name;
        pin = p;
        balance = b;
    }

    bool checkPin(int enteredPin) {
        return pin == enteredPin;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful! New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdraw amount!\n";
            return;
        }

        if (balance < amount) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount user("KAMRAN JARWAR", 8796, 80000);

    int enteredPin;
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (!user.checkPin(enteredPin)) {
        cout << "Wrong PIN! Access Denied.\n";
        return 0;
    }

    int choice;
    double amount;

    do {
        cout << "\n------ ATM MENU ------\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                user.deposit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                user.withdraw(amount);
                break;

            case 3:
                user.showBalance();
                break;

            case 4:
                cout << "Thank you for using ATM!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
