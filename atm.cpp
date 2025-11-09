#include <iostream>
using namespace std;

class Account {
private:
    int accNumber;
    string holderName;
    double accBalance;

public:
    void openAccount() {
        cout << "Enter account number: ";
        cin >> accNumber;
        cout << "Enter holder name: ";
        cin >> holderName;
        cout << "Enter starting balance: ";
        cin >> accBalance;
        cout << "\nAccount created successfully!\n";
    }

    void showAccount() {
        cout << "-------------------------------------\n";
        cout << "Account No: " << accNumber << "\n";
        cout << "Name: " << holderName << "\n";
        cout << "Current Balance: Rs. " << accBalance << "\n";
        cout << "-------------------------------------\n";
    }

    int getNumber() {
        return accNumber;
    }

    void addMoney(double amt) {
        accBalance += amt;
        cout << "Deposited Rs." << amt << " successfully.\n";
        cout << "Updated Balance: Rs." << accBalance << "\n";
    }

    void takeMoney(double amt) {
        if (amt > accBalance) {
            cout << "Not enough balance!\n";
        } else {
            accBalance -= amt;
            cout << "Withdrawal of Rs." << amt << " done.\n";
            cout << "Remaining Balance: Rs." << accBalance << "\n";
        }
    }
};

int main() {
    Account accList[10];
    int total = 0, option, num;
    double amt;

    do {
        cout << "\n====== Bank Management System ======\n";
        cout << "1. Open New Account\n";
        cout << "2. View Account\n";
        cout << "3. Deposit Amount\n";
        cout << "4. Withdraw Amount\n";
        cout << "5. Exit\n";
        cout << "Select option: ";
        cin >> option;

        switch (option) {
            case 1:
                if (total < 10) {
                    accList[total].openAccount();
                    total++;
                } else {
                    cout << "Account limit reached!\n";
                }
                break;

            case 2: {
                cout << "Enter account number to view: ";
                cin >> num;
                bool exists = false;
                for (int i = 0; i < total; i++) {
                    if (accList[i].getNumber() == num) {
                        accList[i].showAccount();
                        exists = true;
                        break;
                    }
                }
                if (!exists)
                    cout << "Account not found!\n";
                break;
            }

            case 3: {
                cout << "Enter account number: ";
                cin >> num;
                cout << "Enter deposit amount: ";
                cin >> amt;
                bool done = false;
                for (int i = 0; i < total; i++) {
                    if (accList[i].getNumber() == num) {
                        accList[i].addMoney(amt);
                        done = true;
                        break;
                    }
                }
                if (!done)
                    cout << "Account not found!\n";
                break;
            }

            case 4: {
                cout << "Enter account number: ";
                cin >> num;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                bool success = false;
                for (int i = 0; i < total; i++) {
                    if (accList[i].getNumber() == num) {
                        accList[i].takeMoney(amt);
                        success = true;
                        break;
                    }
                }
                if (!success)
                    cout << "Account not found!\n";
                break;
            }

            case 5:
                cout << "\nThank you for using our system.\n";
                cout << "Program ended successfully.\n";
                break;

            default:
                cout << "Invalid input! Try again.\n";
        }

    } while (option != 5);

    return 0;
}
