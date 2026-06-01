#include <iostream>
#include <string>
using namespace std;
 
double Balance = 0.0;
double transactionHistory[100]; 
int transactionCount = 0;       

bool authenticateUser();
void displayMenu();
void checkBalance();
void depositMoney();
void withdrawMoney();
void viewTransactionHistory();

int main() {

    int Choice;
    bool Running = true;

    cout << "\t\t\t===Simple ATM System===" << endl;

    
    if (authenticateUser() == false) {
        cout << "Too many incorrect attempts. Program closing." << endl;
        return 0;
    }

    while (Running == true) {
        displayMenu();
        cout << "\t\t\tPlease select an option (1-5): ";
        cin >> Choice;

        if (Choice == 1) {
            checkBalance();
        } 
        else if (Choice == 2) {
            depositMoney();
        } 
        else if (Choice == 3) {
            withdrawMoney();
        } 
        else if (Choice == 4) {
            viewTransactionHistory();
        } 
        else if (Choice == 5) {
            cout << "\t\t\tThank you for using our ATM. " << endl;
            break;
        } 
        else {
            cout << "\t\t\tInvalid selection. Please try again." << endl;
        }
    }

    return 0;
}
bool authenticateUser() {
    string defaultPin = "1234";
    string Pin;
    int attempts = 0;

    while (attempts < 3) {
        cout << "\t\t\tEnter your 4-digit PIN (Default is 1234): ";
        cin >> Pin;

        if (Pin == defaultPin) {
            cout << "\t\t\tEntered successful!" << endl;
            return true;
        } else {
            attempts++;
            cout << "\t\t\tIncorrect PIN. Attempts used: " << attempts << "/3" << endl;
        }
    }
    return false; 
}
void displayMenu() {
    cout << "\t\t\t=== ATM MENU ===" << endl;
    cout << "\t\t\t1. Check Balance" << endl;
    cout << "\t\t\t2. Deposit Money" << endl;
    cout << "\t\t\t3. Withdraw Money" << endl;
    cout << "\t\t\t4. View Transaction History" << endl;
    cout << "\t\t\t5. Exit" << endl;
    cout << "\t\t\t----------------" << endl;
}
void checkBalance() {
    double balance;
    cout << "\t\t\tYour current balance is: " << Balance << "" << endl;
}
void depositMoney() {
    double depositAmount;

    cout << "\t\t\tEnter amount to deposit: ";
    cin >> depositAmount;

    if (depositAmount > 0) {
        Balance = Balance + depositAmount; 
        
        transactionHistory[transactionCount] = depositAmount;
        transactionCount++; 
        
        cout << "\t\t\tSuccessfully deposited: " << depositAmount << "" << endl;
    } else {
        cout << "\t\t\tInvalid amount!" << endl;
    }
}
void withdrawMoney() {
    double withdrawalAmount;

    cout << "\t\t\tEnter amount to withdraw: ";
    cin >> withdrawalAmount;

    if (withdrawalAmount > Balance) {
        cout << "\t\t\tError: Insufficient funds!" << endl;
    } else if (withdrawalAmount <= 0) {
        cout << "\t\t\tInvalid amount!" << endl;
    } else {
        Balance -=  withdrawalAmount; 
        
        transactionHistory[transactionCount] = -withdrawalAmount;
        transactionCount++; // Move to next slot in array
        
        cout << "\t\t\tSuccessfully withdrew: " << withdrawalAmount << "" << endl;
    }
}
void viewTransactionHistory() {
    cout << "\t\t\t=== Transaction History ===" << endl;

    if (transactionCount == 0) {
        cout << "\t\t\tNo transactions completed yet." << endl;
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        if (transactionHistory[i] > 0) {
            cout << "\t\t\t" << (i + 1) << ". Deposit:    " << transactionHistory[i] << "" << endl;
        } else {

            cout << "\t\t\t" << (i + 1) << ". Withdrawal: " << -transactionHistory[i] << "" << endl;
        }
    }
}