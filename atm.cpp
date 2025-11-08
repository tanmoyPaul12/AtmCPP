#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accNo;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account Created Successfully!\n";
    }

    void displayAccount() {
        cout << "Account No: " << accNo
             << " | Name: " << name
             << " | Balance: Rs." << balance << endl;
    }

    int getAccNo() {
        return accNo;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
        cout << "Updated Balance: Rs." << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient Balance!\n";
        else {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
            cout << "Updated Balance: Rs." << balance << endl;
        }
    }
};

int main() {
    BankAccount accounts[10];
    int count = 0, choice, accNo;
    double amount;

    do {
        cout << "\n--- Bank Account Management ---\n";
        cout << "1. Create Account\n";
        cout << "2. Search Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                accounts[count].createAccount();
                count++;
                break;

            case 2:
                cout << "Enter Account Number to search: ";
                cin >> accNo;
                {
                    bool found = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getAccNo() == accNo) {
                            accounts[i].displayAccount();
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Account not found!\n";
                }
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                {
                    bool found = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getAccNo() == accNo) {
                            accounts[i].deposit(amount);
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Account not found!\n";
                }
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                {
                    bool found = false;
                    for (int i = 0; i < count; i++) {
                        if (accounts[i].getAccNo() == accNo) {
                            accounts[i].withdraw(amount);
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Account not found!\n";
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                cout<< "Program Successfully Ended.";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}