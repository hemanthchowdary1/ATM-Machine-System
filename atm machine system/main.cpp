#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Function prototypes
int printDetails();
double readDatabase();
int anotherTransaction();
void appendDatabase(double amount);

int main() {
    int pin, command = 0, attempt = 0, password = 123; // Default password 123
    double accountBal;
    bool isTrue = true;

    cout << "====== HEMANTH KUMAR'S BANK =======\n";
    cout << "Please enter your card\n\n";

    accountBal = readDatabase();
    cout << setprecision(2) << fixed << "Current Balance: INR " << accountBal << endl;
    // Loads amount into accountBal

    // Do-while loop to check password input and attempt counter
    do {
        cout << "\nEnter pin: ";
        cin >> pin;

        if (pin == password) {
            // ATM body
            while (command != 4) {
                command = printDetails();

                switch (command) {
                    int withdraw;
                    int deposit;

                    case 1: // Withdraw
                        cout << "\n             WITHDRAW\n";
                        cout << "\nEnter amount: ";
                        cin >> withdraw;

                        if (accountBal >= withdraw) {
                            accountBal -= withdraw;
                            appendDatabase(accountBal); // Append new account balance to database
                            cout << "Please get your money\n\n";
                        } else {
                            cout << "INVALID AMOUNT\n\n";
                        }
                        command = anotherTransaction();
                        break;

                    case 2: // Deposit
                        cout << "\nDEPOSIT\n";
                        cout << "\nEnter amount: ";
                        cin >> deposit;

                        accountBal += deposit;
                        appendDatabase(accountBal);

                        command = anotherTransaction();
                        break;

                    case 3: // Balance Inquiry
                        cout << "\nExisting Balance = INR " << accountBal << endl;
                        command = anotherTransaction();
                        break;

                    case 4: // Quit
                        cout << "Thank you for using Hemanth Kumar's Bank!" << endl;
                        break;

                    default:
                        cout << "Invalid selection. Please choose again.\n";
                        command = anotherTransaction();
                        break;
                }
            }
            isTrue = false;
        } else {
            attempt++;
            // Increases pin attempt up to 3 chances
            if (attempt == 3) {
                cout << "Max attempts reached, card captured!";
                isTrue = false; // Changes bool condition to false, program exits
            } else {
                cout << "\nWRONG PIN\n";
            }
        }
    } while (isTrue);

    return 0;
}

// Prints services function
int printDetails() {
    int select;

    cout << endl;
    cout << "       1   WITHDRAW" << endl;
    cout << "       2   DEPOSIT" << endl;
    cout << "       3   BALANCE INQUIRY" << endl;
    cout << "       4   QUIT PROGRAM" << endl;

    cout << "       Press selection: ";
    cin >> select;
    cout << "=======================================";
    return select;
}

// Reads database text file
double readDatabase() {
    double accountBalance = 0.0;
    vector<double> balance;

    // Reads and opens database text file
    ifstream file("BDO Database.txt");

    if (file.is_open()) {
        while (file >> accountBalance) {
            balance.push_back(accountBalance);
        }
        file.close();
        if (!balance.empty()) {
            return balance.back();
        } else {
            cout << "No previous balance found. Starting with INR 0." << endl;
            return 0.0;
        }
    } else {
        cout << "Error opening file. Please ensure 'BDO Database.txt' exists." << endl;
        return 0.0;
    }
}

// Repeat transaction function
int anotherTransaction() {
    char YesNo;
    cout << "Do you want another transaction? Y/N\n";
    cin >> YesNo;

    if (YesNo == 'Y' || YesNo == 'y') {
        return 0;
    } else {
        cout << endl << "Please get your card" << endl;
        return 4;
    }
}

// Rewrite last transaction in fstream file
void appendDatabase(double amount) {
    ofstream file("BDO Database.txt", ios::trunc);

    if (file.is_open()) {
        file << amount << endl;
        file.close();
    } else {
        cout << "Error opening file for writing." << endl;
    }
}
