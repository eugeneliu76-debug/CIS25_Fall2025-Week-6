#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
        } else {
            balance -= cost;
            cout << "Purchased " << item << " for $" << cost << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }
};

int main() {
    BankAccount myAccount;

    myAccount.deposit(200.00);
    myAccount.makePurchase("Coffee", 5.00);
    myAccount.makePurchase("Book", 25.50);
    myAccount.displayBalance();

    return 0;
}
