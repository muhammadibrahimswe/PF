// ============================================
// Bank Management System - Customer Module
// ============================================
// Implementation of customer registration,
// login, and all customer banking operations.
// ============================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "../headers/structs.h"
#include "../headers/globals.h"
#include "../headers/utils.h"
#include "../headers/filehandling.h"
#include "../headers/customer.h"

using namespace std;

// ============================================
// Customer Section Menu
// ============================================

void customerMenu() {
    int choice;

    do {
        printHeader("CUSTOMER SECTION");

        setColor(14);
        cout << "  [1] Register New Account" << endl;
        cout << "  [2] Login to Account" << endl;
        cout << "  [0] Back to Main Menu" << endl;
        resetColor();

        cout << endl;
        cout << "  Enter Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: registerCustomer(); break;
            case 2: loginCustomer(); break;
            case 0: break;
            default:
                printError("Invalid choice!");
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// ============================================
// FR-C1: Customer Registration
// ============================================

void registerCustomer() {
    printHeader("NEW ACCOUNT REGISTRATION");

    Customer c;
    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    if (count >= MAX_CUSTOMERS) {
        printError("Maximum customer limit reached! Contact admin.");
        pressEnterToContinue();
        return;
    }

    // Auto-generate account number
    c.accountNumber = getNextAccountNumber();

    cin.ignore(); // Clear buffer

    // ---- Full Name ----
    cout << "  Enter Full Name: ";
    getline(cin, c.name);
    if (c.name.empty()) {
        printError("Name cannot be empty!");
        pressEnterToContinue();
        return;
    }

    // ---- CNIC ----
    cout << "  Enter CNIC (e.g., 35201-1234567-1): ";
    getline(cin, c.cnic);
    if (c.cnic.empty()) {
        printError("CNIC cannot be empty!");
        pressEnterToContinue();
        return;
    }

    // Check for duplicate CNIC
    for (int i = 0; i < count; i++) {
        if (customers[i].cnic == c.cnic) {
            printError("An account with this CNIC already exists!");
            pressEnterToContinue();
            return;
        }
    }

    // ---- Phone ----
    cout << "  Enter Phone Number: ";
    getline(cin, c.phone);
    if (c.phone.empty()) {
        printError("Phone number cannot be empty!");
        pressEnterToContinue();
        return;
    }

    // ---- Address ----
    cout << "  Enter Address: ";
    getline(cin, c.address);

    // ---- Account Type ----
    cout << endl;
    setColor(11);
    cout << "  Select Account Type:" << endl;
    resetColor();
    cout << "  [1] Savings Account" << endl;
    cout << "  [2] Current Account" << endl;
    cout << "  Enter Choice: ";
    int typeChoice;
    cin >> typeChoice;
    c.accountType = (typeChoice == 2) ? "Current" : "Savings";
    cout << endl;

    // ---- Password ----
    string password;
    do {
        cout << "  Create Password: ";
        password = maskPasswordInput();
        if (!validatePassword(password)) {
            printError("Password must be 8+ chars with at least:");
            cout << "    - 1 uppercase letter (A-Z)" << endl;
            cout << "    - 1 lowercase letter (a-z)" << endl;
            cout << "    - 1 digit (0-9)" << endl;
            cout << "    - 1 special character (@#$!%)" << endl;
            printWarning("Example: Ali@1234");
        }
    } while (!validatePassword(password));
    c.password = password;

    // ---- ATM PIN ----
    int pin;
    do {
        cout << "  Create 4-digit ATM PIN: ";
        pin = maskPINInput();
        if (!validatePIN(pin)) {
            printError("PIN must be exactly 4 digits (1000-9999).");
        }
    } while (!validatePIN(pin));
    c.pin = pin;

    // ---- Initial Deposit ----
    cout << "  Enter Initial Deposit (PKR 0 or more): ";
    cin >> c.balance;
    if (c.balance < 0) c.balance = 0;

    c.isLocked = false;

    // Save customer to file
    saveCustomer(c);

    // Record initial deposit transaction
    if (c.balance > 0) {
        Transaction t;
        t.transactionID = getNextTransactionID();
        t.accountNumber = c.accountNumber;
        t.type = "Deposit";
        t.amount = c.balance;
        t.dateTime = getCurrentDateTime();
        saveTransaction(t);
    }

    // Show success with account details
    cout << endl;
    printLine(44);
    setColor(10); // Green
    cout << "    REGISTRATION SUCCESSFUL!" << endl;
    cout << endl;
    cout << "    Your Account Number: " << c.accountNumber << endl;
    cout << "    Account Type       : " << c.accountType << endl;
    cout << "    Initial Balance    : PKR " << fixed << setprecision(2) << c.balance << endl;
    resetColor();
    printLine(44);

    printWarning("Please remember your Account Number, Password, and PIN!");
    pressEnterToContinue();
}

// ============================================
// Customer Login
// ============================================

void loginCustomer() {
    printHeader("CUSTOMER LOGIN");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);

    if (index == -1) {
        printError("Account not found! Please check your account number.");
        pressEnterToContinue();
        return;
    }

    // Check if account is locked
    if (customers[index].isLocked) {
        printError("Your account is currently LOCKED.");
        printWarning("Please contact the bank administrator to unlock your account.");
        pressEnterToContinue();
        return;
    }

    // Password verification with attempt limit
    int attempts = 0;

    while (attempts < MAX_LOGIN_ATTEMPTS) {
        cout << "  Enter Password: ";
        string password = maskPasswordInput();

        if (password == customers[index].password) {
            printSuccess("Login Successful! Welcome, " + customers[index].name + "!");
            pressEnterToContinue();
            customerDashboard(accNo);
            return;
        } else {
            attempts++;
            int remaining = MAX_LOGIN_ATTEMPTS - attempts;

            if (remaining > 0) {
                printError("Incorrect password! " + to_string(remaining) + " attempt(s) remaining.");
            } else {
                // Lock account after max failed attempts
                printError("Maximum login attempts exceeded!");
                customers[index].isLocked = true;
                saveAllCustomers(customers, count);
                printWarning("Your account has been LOCKED for security.");
                printWarning("Contact bank admin to unlock your account.");
            }
        }
    }

    pressEnterToContinue();
}

// ============================================
// Customer Dashboard
// ============================================

void customerDashboard(int accountNumber) {
    int choice;

    do {
        printHeader("CUSTOMER DASHBOARD");

        // Load fresh data to show current name and balance
        Customer customers[MAX_CUSTOMERS];
        int count = loadAllCustomers(customers, MAX_CUSTOMERS);
        int index = findCustomerIndex(customers, count, accountNumber);

        if (index != -1) {
            setColor(10); // Green
            cout << "  Welcome, " << customers[index].name << "!";
            resetColor();
            cout << "  (Acc# " << accountNumber << ")" << endl;
            cout << "  Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
            cout << endl;
        }

        setColor(14);
        cout << "  [1] View Profile" << endl;
        cout << "  [2] Check Balance" << endl;
        cout << "  [3] Deposit Money" << endl;
        cout << "  [4] Withdraw Money" << endl;
        cout << "  [5] Transfer Money" << endl;
        cout << "  [6] Change Password" << endl;
        cout << "  [7] Transaction History" << endl;
        cout << "  [0] Logout" << endl;
        resetColor();

        cout << endl;
        cout << "  Enter Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: viewProfile(accountNumber); break;
            case 2: checkBalance(accountNumber); break;
            case 3: customerDeposit(accountNumber); break;
            case 4: customerWithdraw(accountNumber); break;
            case 5: customerTransfer(accountNumber); break;
            case 6: changePassword(accountNumber); break;
            case 7: viewMyTransactions(accountNumber); break;
            case 0:
                printSuccess("Logged out successfully. Goodbye!");
                pressEnterToContinue();
                break;
            default:
                printError("Invalid choice! Please try again.");
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// ============================================
// FR-C2: View Profile
// ============================================

void viewProfile(int accountNumber) {
    printHeader("MY PROFILE");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account data not found!");
        pressEnterToContinue();
        return;
    }

    setColor(11);
    cout << "  ======================================" << endl;
    cout << "          ACCOUNT INFORMATION           " << endl;
    cout << "  ======================================" << endl;
    resetColor();
    cout << endl;
    cout << "  Account Number : " << customers[index].accountNumber << endl;
    cout << "  Full Name      : " << customers[index].name << endl;
    cout << "  CNIC           : " << customers[index].cnic << endl;
    cout << "  Phone Number   : " << customers[index].phone << endl;
    cout << "  Address        : " << customers[index].address << endl;
    cout << "  Account Type   : " << customers[index].accountType << endl;
    setColor(10);
    cout << "  Current Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    resetColor();
    cout << "  Account Status : " << (customers[index].isLocked ? "Locked" : "Active") << endl;

    pressEnterToContinue();
}

// ============================================
// FR-C3: Check Balance
// ============================================

void checkBalance(int accountNumber) {
    printHeader("BALANCE INQUIRY");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account data not found!");
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

        // Display balance info
        cout << endl;
        setColor(11);
        cout << "  Account Number  : " << accountNumber << endl;
        cout << "  Account Holder  : " << customers[index].name << endl;
        resetColor();
        cout << endl;
        setColor(10);
        cout << "  Current Balance : PKR " << fixed << setprecision(2) << customers[index].balance << endl;
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
        cout << "  Account Number  : " << accountNumber << endl;
        cout << "  Account Holder  : " << customers[index].name << endl;
        resetColor();
        cout << endl;
        setColor(10);
        cout << "  Current Balance : PKR " << fixed << setprecision(2) << customers[index].balance << endl;
        resetColor();
    }

    cout << endl;
    cout << "  Date/Time: " << getCurrentDateTime() << endl;

    pressEnterToContinue();
}

// ============================================
// FR-C4: Deposit Money
// ============================================

void customerDeposit(int accountNumber) {
    printHeader("DEPOSIT MONEY");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account data not found!");
        pressEnterToContinue();
        return;
    }

    cout << "  Current Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    double amount;
    cout << "  Enter Deposit Amount: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Deposit amount must be positive!");
        pressEnterToContinue();
        return;
    }

    // Update balance and save
    customers[index].balance += amount;
    saveAllCustomers(customers, count);

    // Record transaction
    Transaction t;
    t.transactionID = getNextTransactionID();
    t.accountNumber = accountNumber;
    t.type = "Deposit";
    t.amount = amount;
    t.dateTime = getCurrentDateTime();
    saveTransaction(t);

    showProcessing("Processing deposit");
    printReceipt("Deposit", accountNumber, amount, customers[index].balance);
    printSuccess("Deposit successful!");
    pressEnterToContinue();
}

// ============================================
// FR-C5: Withdraw Money
// ============================================

void customerWithdraw(int accountNumber) {
    printHeader("WITHDRAW MONEY");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account data not found!");
        pressEnterToContinue();
        return;
    }

    cout << "  Current Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    double amount;
    cout << "  Enter Withdrawal Amount: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Withdrawal amount must be positive!");
        pressEnterToContinue();
        return;
    }

    if (amount > customers[index].balance) {
        printError("Insufficient balance! You only have PKR " + to_string(customers[index].balance));
        pressEnterToContinue();
        return;
    }

    // Update balance and save
    customers[index].balance -= amount;
    saveAllCustomers(customers, count);

    // Record transaction
    Transaction t;
    t.transactionID = getNextTransactionID();
    t.accountNumber = accountNumber;
    t.type = "Withdrawal";
    t.amount = amount;
    t.dateTime = getCurrentDateTime();
    saveTransaction(t);

    showProcessing("Processing withdrawal");
    printReceipt("Withdrawal", accountNumber, amount, customers[index].balance);
    printSuccess("Withdrawal successful!");
    pressEnterToContinue();
}

// ============================================
// FR-C6: Transfer Money
// ============================================

void customerTransfer(int accountNumber) {
    printHeader("TRANSFER MONEY");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account data not found!");
        pressEnterToContinue();
        return;
    }

    cout << "  Your Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    // Get receiver account
    int toAcc;
    cout << "  Enter Receiver Account Number: ";
    cin >> toAcc;

    if (toAcc == accountNumber) {
        printError("Cannot transfer to your own account!");
        pressEnterToContinue();
        return;
    }

    int toIndex = findCustomerIndex(customers, count, toAcc);
    if (toIndex == -1) {
        printError("Receiver account not found!");
        pressEnterToContinue();
        return;
    }

    if (customers[toIndex].isLocked) {
        printError("Receiver account is currently locked!");
        pressEnterToContinue();
        return;
    }

    cout << "  Receiver: " << customers[toIndex].name << " (Acc# " << toAcc << ")" << endl;
    cout << endl;

    // Get transfer amount
    double amount;
    cout << "  Enter Transfer Amount: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Transfer amount must be positive!");
        pressEnterToContinue();
        return;
    }

    if (amount > customers[index].balance) {
        printError("Insufficient balance!");
        pressEnterToContinue();
        return;
    }

    // Execute transfer
    customers[index].balance -= amount;
    customers[toIndex].balance += amount;
    saveAllCustomers(customers, count);

    // Record sender transaction
    Transaction t1;
    t1.transactionID = getNextTransactionID();
    t1.accountNumber = accountNumber;
    t1.type = "Transfer-Out";
    t1.amount = amount;
    t1.dateTime = getCurrentDateTime();
    saveTransaction(t1);

    // Record receiver transaction
    Transaction t2;
    t2.transactionID = getNextTransactionID();
    t2.accountNumber = toAcc;
    t2.type = "Transfer-In";
    t2.amount = amount;
    t2.dateTime = getCurrentDateTime();
    saveTransaction(t2);

    showProcessing("Processing transfer");
    printReceipt("Transfer-Out", accountNumber, amount, customers[index].balance);
    printSuccess("Transfer successful!");
    cout << "  PKR " << fixed << setprecision(2) << amount << " sent to " << customers[toIndex].name << " (Acc# " << toAcc << ")" << endl;

    pressEnterToContinue();
}

// ============================================
// FR-C7: Change Password
// ============================================

void changePassword(int accountNumber) {
    printHeader("CHANGE PASSWORD");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);
    int index = findCustomerIndex(customers, count, accountNumber);

    if (index == -1) {
        printError("Account data not found!");
        pressEnterToContinue();
        return;
    }

    // Step 1: Verify current password
    cout << "  Enter Current Password: ";
    string oldPass = maskPasswordInput();

    if (oldPass != customers[index].password) {
        printError("Incorrect current password!");
        pressEnterToContinue();
        return;
    }

    // Step 2: Get new password with validation
    string newPass;
    bool valid = false;

    do {
        cout << "  Enter New Password: ";
        newPass = maskPasswordInput();

        if (!validatePassword(newPass)) {
            printError("Password must be 8+ chars with uppercase, lowercase, digit, and special character.");
            continue;
        }

        if (newPass == oldPass) {
            printError("New password must be different from current password!");
            continue;
        }

        valid = true;
    } while (!valid);

    // Step 3: Confirm new password
    cout << "  Confirm New Password: ";
    string confirmPass = maskPasswordInput();

    if (newPass != confirmPass) {
        printError("Passwords do not match! Password change cancelled.");
        pressEnterToContinue();
        return;
    }

    // Save updated password
    customers[index].password = newPass;
    saveAllCustomers(customers, count);
    printSuccess("Password changed successfully!");
    pressEnterToContinue();
}

// ============================================
// FR-C8: View My Transaction History
// ============================================

void viewMyTransactions(int accountNumber) {
    printHeader("MY TRANSACTION HISTORY");

    Transaction transactions[MAX_TRANSACTIONS];
    int count = loadAllTransactions(transactions, MAX_TRANSACTIONS);

    // Table header
    setColor(11);
    cout << "  " << left
         << setw(10) << "Txn ID"
         << setw(16) << "Type"
         << setw(14) << "Amount"
         << "Date/Time" << endl;
    resetColor();
    printLine(60);

    int found = 0;

    // Display transactions belonging to this account
    for (int i = 0; i < count; i++) {
        if (transactions[i].accountNumber == accountNumber) {
            cout << "  " << left
                 << setw(10) << transactions[i].transactionID
                 << setw(16) << transactions[i].type
                 << "PKR " << setw(10) << fixed << setprecision(2) << transactions[i].amount
                 << transactions[i].dateTime << endl;
            found++;
        }
    }

    if (found == 0) {
        printWarning("No transactions found for your account.");
    } else {
        printLine(60);
        setColor(11);
        cout << "  Total Transactions: " << found << endl;
        resetColor();
    }

    pressEnterToContinue();
}
