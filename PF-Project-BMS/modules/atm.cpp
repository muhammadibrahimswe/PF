// ============================================
// Bank Management System - ATM Module
// ============================================
// Implementation of ATM authentication and
// operations: balance inquiry, cash withdrawal,
// fast cash, mini statement, and PIN change.
// ============================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "../headers/structs.h"
#include "../headers/globals.h"
#include "../headers/utils.h"
#include "../headers/filehandling.h"
#include "../headers/atm.h"

using namespace std;

// ============================================
// ATM Section Entry (Login with PIN)
// ============================================

void atmSection() {
    printHeader("ATM SECTION");

    setColor(11);
    cout << "  ===============================" << endl;
    cout << "      WELCOME TO BMS ATM         " << endl;
    cout << "  ===============================" << endl;
    resetColor();
    cout << endl;

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    // Get account number
    int accNo;
    cout << "  Enter Your Account Number: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);

    if (index == -1) {
        printError("Account not found! Please check your account number.");
        pressEnterToContinue();
        return;
    }

    // Check if account is locked
    if (customers[index].isLocked) {
        printError("Your account is LOCKED.");
        printWarning("Please visit the bank or contact admin.");
        pressEnterToContinue();
        return;
    }

    // PIN verification with 3 attempts
    int attempts = 0;

    while (attempts < MAX_LOGIN_ATTEMPTS) {
        cout << "  Enter ATM PIN: ";
        int pin = maskPINInput();

        if (pin == customers[index].pin) {
            printSuccess("ATM Access Granted!");
            pressEnterToContinue();
            atmMenu(accNo);
            return;
        } else {
            attempts++;
            int remaining = MAX_LOGIN_ATTEMPTS - attempts;

            if (remaining > 0) {
                printError("Incorrect PIN! " + to_string(remaining) + " attempt(s) remaining.");
            } else {
                printError("Maximum PIN attempts exceeded!");
                printWarning("ATM session has been blocked. Please try again later.");
            }
        }
    }

    pressEnterToContinue();
}

// ============================================
// ATM Menu
// ============================================

void atmMenu(int accountNumber) {
    int choice;

    do {
        printHeader("ATM MENU");

        setColor(11);
        cout << "  ===============================" << endl;
        cout << "          BMS ATM SERVICES       " << endl;
        cout << "  ===============================" << endl;
        resetColor();
        cout << endl;

        setColor(14);
        cout << "  [1] Balance Inquiry" << endl;
        cout << "  [2] Cash Withdrawal" << endl;
        cout << "  [3] Fast Cash" << endl;
        cout << "  [4] Mini Statement" << endl;
        cout << "  [5] PIN Change" << endl;
        cout << "  [0] Exit ATM" << endl;
        resetColor();

        cout << endl;
        cout << "  Select Option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: balanceInquiry(accountNumber); break;
            case 2: cashWithdrawal(accountNumber); break;
            case 3: fastCash(accountNumber); break;
            case 4: miniStatement(accountNumber); break;
            case 5: changePin(accountNumber); break;
            case 0:
                cout << endl;
                setColor(10);
                cout << "  =================================" << endl;
                cout << "   Thank you for using BMS ATM!    " << endl;
                cout << "   Please take your card.          " << endl;
                cout << "  =================================" << endl;
                resetColor();
                pressEnterToContinue();
                break;
            default:
                printError("Invalid option! Please try again.");
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// ============================================
// FR-ATM1: Balance Inquiry
// ============================================

void balanceInquiry(int accountNumber) {
    printHeader("BALANCE INQUIRY");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account error! Please contact bank.");
        pressEnterToContinue();
        return;
    }

    // ---- Zakat Auto-Deduction ----
    const double NISAB_THRESHOLD = 3000000.00; // PKR 3,000,000
    const double ZAKAT_RATE = 0.025;           // 2.5%

    // Check if zakat was already deducted for this account
    Transaction transactions[MAX_TRANSACTIONS];
    int txnCount = loadAllTransactions(transactions, MAX_TRANSACTIONS);
    bool alreadyDeducted = false;

    for (int i = 0; i < txnCount; i++) {
        if (transactions[i].accountNumber == accountNumber && transactions[i].type == "Zakat-Deduction") {
            alreadyDeducted = true;
            break;
        }
    }

    if (customers[index].balance > NISAB_THRESHOLD && !alreadyDeducted) {
        double zakatAmount = customers[index].balance * ZAKAT_RATE;

        // Deduct zakat from balance
        customers[index].balance -= zakatAmount;
        saveAllCustomers(customers, count);

        // Record zakat transaction
        Transaction t;
        t.transactionID = getNextTransactionID();
        t.accountNumber = accountNumber;
        t.type = "Zakat-Deduction";
        t.amount = zakatAmount;
        t.dateTime = getCurrentDateTime();
        saveTransaction(t);

        cout << endl;
        setColor(11);
        cout << "  =================================" << endl;
        cout << "       BALANCE INFORMATION         " << endl;
        cout << "  =================================" << endl;
        resetColor();
        cout << endl;
        cout << "  Account Number  : " << accountNumber << endl;
        cout << "  Account Holder  : " << customers[index].name << endl;
        cout << "  Account Type    : " << customers[index].accountType << endl;
        cout << endl;
        setColor(10);
        cout << "  Available Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
        resetColor();
        cout << endl;

        // Zakat notification
        setColor(14); // Yellow
        cout << "  +-------------------------------------------------+" << endl;
        cout << "  |              ZAKAT NOTIFICATION                  |" << endl;
        cout << "  +-------------------------------------------------+" << endl;
        cout << "  |  Zakat of 2.5% has been deducted from your      |" << endl;
        cout << "  |  account and transferred to the zakat fund.     |" << endl;
        cout << "  +-------------------------------------------------+" << endl;
        resetColor();
        cout << endl;
        setColor(12); // Red for deduction
        cout << "  Zakat Deducted  : PKR " << fixed << setprecision(2) << zakatAmount << endl;
        resetColor();
        setColor(10);
        cout << "  Balance After   : PKR " << fixed << setprecision(2) << customers[index].balance << endl;
        resetColor();
    } else {
        // Balance below nisab OR zakat already deducted — no deduction
        cout << endl;
        setColor(11);
        cout << "  =================================" << endl;
        cout << "       BALANCE INFORMATION         " << endl;
        cout << "  =================================" << endl;
        resetColor();
        cout << endl;
        cout << "  Account Number  : " << accountNumber << endl;
        cout << "  Account Holder  : " << customers[index].name << endl;
        cout << "  Account Type    : " << customers[index].accountType << endl;
        cout << endl;
        setColor(10);
        cout << "  Available Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
        resetColor();
    }

    cout << endl;
    cout << "  Date/Time: " << getCurrentDateTime() << endl;

    pressEnterToContinue();
}

// ============================================
// FR-ATM2: Cash Withdrawal
// ============================================

void cashWithdrawal(int accountNumber) {
    printHeader("CASH WITHDRAWAL");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account error! Please contact bank.");
        pressEnterToContinue();
        return;
    }

    cout << "  Available Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    double amount;
    cout << "  Enter Amount to Withdraw: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Amount must be positive!");
        pressEnterToContinue();
        return;
    }

    if (amount > customers[index].balance) {
        printError("Insufficient balance!");
        cout << "  Available: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
        pressEnterToContinue();
        return;
    }

    // Process withdrawal
    customers[index].balance -= amount;
    saveAllCustomers(customers, count);

    // Record transaction
    Transaction t;
    t.transactionID = getNextTransactionID();
    t.accountNumber = accountNumber;
    t.type = "ATM-Withdrawal";
    t.amount = amount;
    t.dateTime = getCurrentDateTime();
    saveTransaction(t);

    showProcessing("Dispensing cash");
    printReceipt("ATM-Withdrawal", accountNumber, amount, customers[index].balance);

    setColor(10);
    cout << endl << "  Please collect your cash." << endl;
    resetColor();

    pressEnterToContinue();
}

// ============================================
// FR-ATM3: Fast Cash
// ============================================

void fastCash(int accountNumber) {
    printHeader("FAST CASH");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account error! Please contact bank.");
        pressEnterToContinue();
        return;
    }

    cout << "  Available Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    setColor(14);
    cout << "  Select Amount:" << endl;
    cout << endl;
    cout << "  [1]  PKR    500" << endl;
    cout << "  [2]  PKR  1,000" << endl;
    cout << "  [3]  PKR  5,000" << endl;
    cout << "  [4]  PKR 10,000" << endl;
    cout << "  [0]  Cancel" << endl;
    resetColor();

    cout << endl;
    cout << "  Enter Choice: ";
    int choice;
    cin >> choice;

    double amount = 0;

    switch (choice) {
        case 1: amount = 500;   break;
        case 2: amount = 1000;  break;
        case 3: amount = 5000;  break;
        case 4: amount = 10000; break;
        case 0: return; // Cancel
        default:
            printError("Invalid choice!");
            pressEnterToContinue();
            return;
    }

    // Check balance
    if (amount > customers[index].balance) {
        printError("Insufficient balance for PKR " + to_string((int)amount) + "!");
        cout << "  Available: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
        pressEnterToContinue();
        return;
    }

    // Process fast cash withdrawal
    customers[index].balance -= amount;
    saveAllCustomers(customers, count);

    // Record transaction
    Transaction t;
    t.transactionID = getNextTransactionID();
    t.accountNumber = accountNumber;
    t.type = "ATM-FastCash";
    t.amount = amount;
    t.dateTime = getCurrentDateTime();
    saveTransaction(t);

    showProcessing("Dispensing cash");
    printReceipt("ATM-FastCash", accountNumber, amount, customers[index].balance);

    setColor(10);
    cout << endl << "  Please collect your cash." << endl;
    resetColor();

    pressEnterToContinue();
}

// ============================================
// FR-ATM4: Mini Statement (Last 5 Transactions)
// ============================================

void miniStatement(int accountNumber) {
    printHeader("MINI STATEMENT");

    Transaction transactions[MAX_TRANSACTIONS];
    int count = loadAllTransactions(transactions, MAX_TRANSACTIONS);

    // Count transactions for this account
    int myCount = 0;
    for (int i = 0; i < count; i++) {
        if (transactions[i].accountNumber == accountNumber) {
            myCount++;
        }
    }

    if (myCount == 0) {
        printWarning("No transactions found for your account.");
        pressEnterToContinue();
        return;
    }

    // Calculate how many to skip to show only last 5
    int skip = (myCount > 5) ? (myCount - 5) : 0;

    setColor(11);
    cout << "  Account: " << accountNumber << "  |  Last " << (myCount > 5 ? 5 : myCount) << " Transactions" << endl;
    cout << endl;
    cout << "  " << left
         << setw(10) << "Txn ID"
         << setw(16) << "Type"
         << setw(14) << "Amount"
         << "Date/Time" << endl;
    resetColor();
    printLine(60);

    int currentIndex = 0;
    for (int i = 0; i < count; i++) {
        if (transactions[i].accountNumber == accountNumber) {
            currentIndex++;
            if (currentIndex > skip) {
                cout << "  " << left
                     << setw(10) << transactions[i].transactionID
                     << setw(16) << transactions[i].type
                     << "PKR " << setw(10) << fixed << setprecision(2) << transactions[i].amount
                     << transactions[i].dateTime << endl;
            }
        }
    }

    printLine(60);

    // Also show current balance
    Customer customers[MAX_CUSTOMERS];
    int custCount = loadAllCustomers(customers, MAX_CUSTOMERS);
    int custIndex = findCustomerIndex(customers, custCount, accountNumber);

    if (custIndex != -1) {
        setColor(10);
        cout << "  Available Balance: PKR " << fixed << setprecision(2) << customers[custIndex].balance << endl;
        resetColor();
    }

    pressEnterToContinue();
}

// ============================================
// FR-ATM5: Change ATM PIN
// ============================================

void changePin(int accountNumber) {
    printHeader("CHANGE ATM PIN");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account error! Please contact bank.");
        pressEnterToContinue();
        return;
    }

    // Step 1: Verify current PIN
    cout << "  Enter Current PIN: ";
    int oldPin = maskPINInput();

    if (oldPin != customers[index].pin) {
        printError("Incorrect current PIN!");
        pressEnterToContinue();
        return;
    }

    // Step 2: Get new PIN with validation
    int newPin;
    bool valid = false;

    do {
        cout << "  Enter New 4-digit PIN: ";
        newPin = maskPINInput();

        if (!validatePIN(newPin)) {
            printError("PIN must be exactly 4 digits (1000-9999).");
            continue;
        }

        if (newPin == oldPin) {
            printError("New PIN must be different from current PIN!");
            continue;
        }

        valid = true;
    } while (!valid);

    // Step 3: Confirm new PIN
    cout << "  Confirm New PIN: ";
    int confirmPin = maskPINInput();

    if (newPin != confirmPin) {
        printError("PINs do not match! PIN change cancelled.");
        pressEnterToContinue();
        return;
    }

    // Save updated PIN
    customers[index].pin = newPin;
    saveAllCustomers(customers, count);
    printSuccess("ATM PIN changed successfully!");

    pressEnterToContinue();
}
