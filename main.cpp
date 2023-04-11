#include <iostream>
using namespace std;

class MobileMoney {
private:
    int pin;
    int balance;
    int numOfAttempts;
public:
    MobileMoney() {
        pin = 0000; // default pin
        balance = 1000; // default balance
        numOfAttempts = 0; // number of attempts
    }
    void authenticate(int enteredPin) {
        if (enteredPin == pin) {
            cout << "Authentication successful." << endl;
        } else {
            numOfAttempts++;
            if (numOfAttempts == 3) {
                cout << "Maximum number of attempts reached." << endl;
                exit(0);
            } else {
                cout << "Invalid pin. Please try again." << endl;
                authenticate(enteredPin);
            }
        }
    }
    void resetPin(int newPin) {
        pin = newPin;
        cout << "Pin reset successful." << endl;
    }
    void checkBalance() {
        cout << "Your current balance is: " << balance << endl;
    }
    void sendMoney(int amount) {
        if (balance < amount) {
            cout << "Insufficient balance. Transaction failed." << endl;
        } else {
            balance -= amount;
            cout << "Transaction successful. " << amount << " has been sent." << endl;
            checkBalance();
        }
    }
};

int main() {
    MobileMoney user;
    int option;
    int enteredPin;
    int newPin;
    int amount;

    while (true) {
        cout << "\nWelcome to Mobile Money Service" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset Pin" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter pin: ";
                cin >> enteredPin;
                user.authenticate(enteredPin);
                break;
            case 2:
                cout << "Enter new pin: ";
                cin >> newPin;
                user.resetPin(newPin);
                break;
            case 3:
                user.checkBalance();
                break;
            case 4:
                cout << "Enter amount: ";
                cin >> amount;
                user.sendMoney(amount);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
    return 0;
}
