// ============================================
// Bank Management System - Admin Module
// ============================================
// Implementation of all admin/manager
// functions: login, customer CRUD, banking
// operations, reports, and security.
// ============================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "../headers/structs.h"
#include "../headers/globals.h"
#include "../headers/utils.h"
#include "../headers/filehandling.h"
#include "../headers/admin.h"

using namespace std;

// ============================================
// Admin Authentication
// ============================================

// Admin login with hardcoded credentials
void adminLogin() {
    printHeader("ADMIN / MANAGER LOGIN");

    string username, password;

    cout << "  Enter Username: ";
    cin >> username;

    cout << "  Enter Password: ";
    password = maskPasswordInput();

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        printSuccess("Login Successful! Welcome, Admin.");
        pressEnterToContinue();
        adminMenu();
    } else {
        printError("Invalid Username or Password!");
        pressEnterToContinue();
    }
}

// ============================================
// Admin Dashboard Menu
// ============================================

void adminMenu() {
    int choice;

    do {
        printHeader("ADMIN DASHBOARD");

        setColor(14); // Yellow
        cout << "  [1]  Add Customer Account" << endl;
        cout << "  [2]  View All Customers" << endl;
        cout << "  [3]  Search Customer" << endl;
        cout << "  [4]  Edit Customer Information" << endl;
        cout << "  [5]  Delete Customer Account" << endl;
        cout << "  [6]  Deposit Money" << endl;
        cout << "  [7]  Withdraw Money" << endl;
        cout << "  [8]  Transfer Money" << endl;
        cout << "  [9]  View Transaction History" << endl;
        cout << "  [10] System Statistics" << endl;
        cout << "  [11] Lock Account" << endl;
        cout << "  [12] Unlock Account" << endl;
        cout << "  [0]  Logout" << endl;
        resetColor();

        cout << endl;
        cout << "  Enter Choice: ";
        cin >> choice;

        // Handle invalid (non-numeric) input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:  addCustomer(); break;
            case 2:  viewAllCustomers(); break;
            case 3:  searchCustomer(); break;
            case 4:  editCustomer(); break;
            case 5:  deleteCustomer(); break;
            case 6:  adminDeposit(); break;
            case 7:  adminWithdraw(); break;
            case 8:  adminTransfer(); break;
            case 9:  viewAllTransactions(); break;
            case 10: showStatistics(); break;
            case 11: adminLockAccount(); break;
            case 12: adminUnlockAccount(); break;
            case 0:
                printSuccess("Admin logged out successfully.");
                pressEnterToContinue();
                break;
            default:
                printError("Invalid choice! Please try again.");
                pressEnterToContinue();
        }
    } while (choice != 0);
}

// ============================================
// FR-A1: Add Customer Account
// ============================================

void addCustomer() {
    printHeader("ADD NEW CUSTOMER ACCOUNT");

    Customer c;
    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    if (count >= MAX_CUSTOMERS) {
        printError("Maximum customer limit reached!");
        pressEnterToContinue();
        return;
    }

    // Auto-generate account number
    c.accountNumber = getNextAccountNumber();

    cin.ignore(); // Clear leftover newline from previous cin >>

    // Collect customer information
    cout << "  Enter Full Name: ";
    getline(cin, c.name);
    if (c.name.empty()) {
        printError("Name cannot be empty!");
        pressEnterToContinue();
        return;
    } 

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
            printError("This CNIC is already registered!");
            pressEnterToContinue();
            return;
        }
    }

    cout << "  Enter Phone Number: ";
    getline(cin, c.phone);

    cout << "  Enter Address: ";
    getline(cin, c.address);

    // Account type selection
    int typeChoice;
    cout << "  Account Type (1 = Savings, 2 = Current): ";
    cin >> typeChoice;
    c.accountType = (typeChoice == 2) ? "Current" : "Savings";

    // Password with validation
    string password;
    do {
        cout << "  Set Password: ";
        password = maskPasswordInput();
        if (!validatePassword(password)) {
            printError("Password must be 8+ chars with uppercase, lowercase, digit, and special char.");
            printWarning("Example: Admin@123");
        }
    } while (!validatePassword(password));
    c.password = password;

    // ATM PIN with validation
    int pin;
    do {
        cout << "  Set 4-digit ATM PIN: ";
        pin = maskPINInput();
        if (!validatePIN(pin)) {
            printError("PIN must be exactly 4 digits (1000-9999).");
        }
    } while (!validatePIN(pin));
    c.pin = pin;

    // Initial deposit
    cout << "  Enter Initial Deposit (PKR): ";
    cin >> c.balance;
    if (c.balance < 0) c.balance = 0;

    c.isLocked = false;

    // Save to file
    saveCustomer(c);

    // Record initial deposit transaction if any
    if (c.balance > 0) {
        Transaction t;
        t.transactionID = getNextTransactionID();
        t.accountNumber = c.accountNumber;
        t.type = "Deposit";
        t.amount = c.balance;
        t.dateTime = getCurrentDateTime();
        saveTransaction(t);
    }

    cout << endl;
    printLine(40);
    setColor(10); // Green
    cout << "  Account Created Successfully!" << endl;
    cout << "  Account Number: " << c.accountNumber << endl;
    resetColor();
    printLine(40);

    pressEnterToContinue();
}

// ============================================
// FR-A2: View All Customers
// ============================================

void viewAllCustomers() {
    printHeader("ALL CUSTOMER ACCOUNTS");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    if (count == 0) {
        printWarning("No customers found in the system.");
        pressEnterToContinue();
        return;
    }

    // Print table header
    setColor(11); // Cyan
    cout << "  " << left
         << setw(8)  << "Acc#"
         << setw(18) << "Name"
         << setw(16) << "CNIC"
         << setw(14) << "Phone"
         << setw(10) << "Type"
         << setw(12) << "Balance"
         << setw(8)  << "Status" << endl;
    resetColor();
    printLine(86);

    // Print each customer row
    for (int i = 0; i < count; i++) {
        cout << "  " << left
             << setw(8)  << customers[i].accountNumber
             << setw(18) << customers[i].name
             << setw(16) << customers[i].cnic
             << setw(14) << customers[i].phone
             << setw(10) << customers[i].accountType
             << "PKR " << setw(8) << fixed << setprecision(2) << customers[i].balance
             << (customers[i].isLocked ? "Locked" : "Active") << endl;
    }

    printLine(86);
    setColor(11);
    cout << "  Total Customers: " << count << endl;
    resetColor();

    pressEnterToContinue();
}

// ============================================
// FR-A3: Search Customer
// ============================================

void searchCustomer() {
    printHeader("SEARCH CUSTOMER");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    cout << "  Search by:" << endl;
    cout << "  [1] Account Number" << endl;
    cout << "  [2] CNIC" << endl;
    cout << "  Enter Choice: ";

    int searchChoice;
    cin >> searchChoice;

    int foundIndex = -1;

    if (searchChoice == 1) {
        int accNo;
        cout << "  Enter Account Number: ";
        cin >> accNo;
        foundIndex = findCustomerIndex(customers, count, accNo);
    } else if (searchChoice == 2) {
        string cnic;
        cin.ignore();
        cout << "  Enter CNIC: ";
        getline(cin, cnic);
        foundIndex = findCustomerByCNIC(customers, count, cnic);
    } else {
        printError("Invalid choice!");
        pressEnterToContinue();
        return;
    }

    if (foundIndex == -1) {
        printError("Customer not found!");
    } else {
        cout << endl;
        setColor(11);
        cout << "  -------- Customer Details --------" << endl;
        resetColor();
        cout << "  Account Number : " << customers[foundIndex].accountNumber << endl;
        cout << "  Name           : " << customers[foundIndex].name << endl;
        cout << "  CNIC           : " << customers[foundIndex].cnic << endl;
        cout << "  Phone          : " << customers[foundIndex].phone << endl;
        cout << "  Address        : " << customers[foundIndex].address << endl;
        cout << "  Account Type   : " << customers[foundIndex].accountType << endl;
        cout << "  Balance        : PKR " << fixed << setprecision(2) << customers[foundIndex].balance << endl;
        cout << "  Status         : " << (customers[foundIndex].isLocked ? "Locked" : "Active") << endl;
    }

    pressEnterToContinue();
}

// ============================================
// FR-A4: Edit Customer Information
// ============================================

void editCustomer() {
    printHeader("EDIT CUSTOMER INFORMATION");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);
    if (index == -1) {
        printError("Customer not found!");
        pressEnterToContinue();
        return;
    }

    // Show current info
    cout << endl;
    setColor(11);
    cout << "  Current Information:" << endl;
    resetColor();
    cout << "  Name    : " << customers[index].name << endl;
    cout << "  Phone   : " << customers[index].phone << endl;
    cout << "  Address : " << customers[index].address << endl;
    cout << endl;

    cout << "  What would you like to edit?" << endl;
    cout << "  [1] Phone Number" << endl;
    cout << "  [2] Address" << endl;
    cout << "  [3] Password" << endl;
    cout << "  [4] ATM PIN" << endl;
    cout << "  Enter Choice: ";

    int editChoice;
    cin >> editChoice;
    cin.ignore(); // Clear buffer before getline

    switch (editChoice) {
        case 1:
            cout << "  Enter New Phone Number: ";
            getline(cin, customers[index].phone);
            break;
        case 2:
            cout << "  Enter New Address: ";
            getline(cin, customers[index].address);
            break;
        case 3: {
            string newPass;
            do {
                cout << "  Enter New Password: ";
                newPass = maskPasswordInput();
                if (!validatePassword(newPass)) {
                    printError("Password must meet all requirements (8+ chars, upper, lower, digit, special).");
                }
            } while (!validatePassword(newPass));
            customers[index].password = newPass;
            break;
        }
        case 4: {
            int newPin;
            do {
                cout << "  Enter New 4-digit PIN: ";
                newPin = maskPINInput();
                if (!validatePIN(newPin)) {
                    printError("PIN must be exactly 4 digits (1000-9999).");
                }
            } while (!validatePIN(newPin));
            customers[index].pin = newPin;
            break;
        }
        default:
            printError("Invalid choice!");
            pressEnterToContinue();
            return;
    }

    // Save updated data
    saveAllCustomers(customers, count);
    printSuccess("Customer information updated successfully!");
    pressEnterToContinue();
}

// ============================================
// FR-A5: Delete Customer Account
// ============================================

void deleteCustomer() {
    printHeader("DELETE CUSTOMER ACCOUNT");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number to Delete: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);
    if (index == -1) {
        printError("Customer not found!");
        pressEnterToContinue();
        return;
    }

    // Show account details for confirmation
    cout << endl;
    cout << "  Customer : " << customers[index].name << endl;
    cout << "  Acc#     : " << customers[index].accountNumber << endl;
    cout << "  Balance  : PKR " << fixed << setprecision(2) << customers[index].balance << endl;

    printWarning("This action is PERMANENT and cannot be undone!");

    char confirm;
    cout << "  Are you sure you want to delete? (Y/N): ";
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        // Shift remaining customers to fill the gap
        for (int i = index; i < count - 1; i++) {
            customers[i] = customers[i + 1];
        }
        count--;

        saveAllCustomers(customers, count);
        printSuccess("Customer account deleted successfully!");
    } else {
        printWarning("Deletion cancelled.");
    }

    pressEnterToContinue();
}

// ============================================
// FR-A6: Deposit Money (Admin)
// ============================================

void adminDeposit() {
    printHeader("DEPOSIT MONEY (ADMIN)");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);
    if (index == -1) {
        printError("Account not found!");
        pressEnterToContinue();
        return;
    }

    if (customers[index].isLocked) {
        printError("This account is locked! Unlock it first.");
        pressEnterToContinue();
        return;
    }

    cout << "  Account Holder : " << customers[index].name << endl;
    cout << "  Current Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    double amount;
    cout << "  Enter Deposit Amount: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Amount must be positive!");
        pressEnterToContinue();
        return;
    }

    // Update balance
    customers[index].balance += amount;
    saveAllCustomers(customers, count);

    // Record transaction
    Transaction t;
    t.transactionID = getNextTransactionID();
    t.accountNumber = accNo;
    t.type = "Deposit";
    t.amount = amount;
    t.dateTime = getCurrentDateTime();
    saveTransaction(t);

    showProcessing("Processing deposit");
    printReceipt("Deposit", accNo, amount, customers[index].balance);
    printSuccess("Deposit successful!");
    pressEnterToContinue();
}

// ============================================
// FR-A7: Withdraw Money (Admin)
// ============================================

void adminWithdraw() {
    printHeader("WITHDRAW MONEY (ADMIN)");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);
    if (index == -1) {
        printError("Account not found!");
        pressEnterToContinue();
        return;
    }

    if (customers[index].isLocked) {
        printError("This account is locked! Unlock it first.");
        pressEnterToContinue();
        return;
    }

    cout << "  Account Holder : " << customers[index].name << endl;
    cout << "  Current Balance: PKR " << fixed << setprecision(2) << customers[index].balance << endl;
    cout << endl;

    double amount;
    cout << "  Enter Withdrawal Amount: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Amount must be positive!");
        pressEnterToContinue();
        return;
    }

    if (amount > customers[index].balance) {
        printError("Insufficient balance!");
        pressEnterToContinue();
        return;
    }

    // Update balance
    customers[index].balance -= amount;
    saveAllCustomers(customers, count);

    // Record transaction
    Transaction t;
    t.transactionID = getNextTransactionID();
    t.accountNumber = accNo;
    t.type = "Withdrawal";
    t.amount = amount;
    t.dateTime = getCurrentDateTime();
    saveTransaction(t);

    showProcessing("Processing withdrawal");
    printReceipt("Withdrawal", accNo, amount, customers[index].balance);
    printSuccess("Withdrawal successful!");
    pressEnterToContinue();
}

// ============================================
// FR-A8: Transfer Money (Admin)
// ============================================

void adminTransfer() {
    printHeader("TRANSFER MONEY (ADMIN)");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    // Get sender account
    int fromAcc;
    cout << "  Enter Sender Account Number: ";
    cin >> fromAcc;

    int fromIndex = findCustomerIndex(customers, count, fromAcc);
    if (fromIndex == -1) {
        printError("Sender account not found!");
        pressEnterToContinue();
        return;
    }

    if (customers[fromIndex].isLocked) {
        printError("Sender account is locked!");
        pressEnterToContinue();
        return;
    }

    // Get receiver account
    int toAcc;
    cout << "  Enter Receiver Account Number: ";
    cin >> toAcc;

    if (fromAcc == toAcc) {
        printError("Cannot transfer to the same account!");
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
        printError("Receiver account is locked!");
        pressEnterToContinue();
        return;
    }

    // Show balances
    cout << endl;
    cout << "  Sender   : " << customers[fromIndex].name << " (Balance: PKR " << fixed << setprecision(2) << customers[fromIndex].balance << ")" << endl;
    cout << "  Receiver : " << customers[toIndex].name << " (Acc# " << toAcc << ")" << endl;
    cout << endl;

    // Get transfer amount
    double amount;
    cout << "  Enter Transfer Amount: PKR ";
    cin >> amount;

    if (amount <= 0) {
        printError("Amount must be positive!");
        pressEnterToContinue();
        return;
    }

    if (amount > customers[fromIndex].balance) {
        printError("Insufficient balance in sender account!");
        pressEnterToContinue();
        return;
    }

    // Execute transfer
    customers[fromIndex].balance -= amount;
    customers[toIndex].balance += amount;
    saveAllCustomers(customers, count);

    // Record sender transaction (Transfer-Out)
    Transaction t1;
    t1.transactionID = getNextTransactionID();
    t1.accountNumber = fromAcc;
    t1.type = "Transfer-Out";
    t1.amount = amount;
    t1.dateTime = getCurrentDateTime();
    saveTransaction(t1);

    // Record receiver transaction (Transfer-In)
    Transaction t2;
    t2.transactionID = getNextTransactionID();
    t2.accountNumber = toAcc;
    t2.type = "Transfer-In";
    t2.amount = amount;
    t2.dateTime = getCurrentDateTime();
    saveTransaction(t2);

    showProcessing("Processing transfer");
    printReceipt("Transfer-Out", fromAcc, amount, customers[fromIndex].balance);
    printSuccess("Transfer successful!");
    cout << "  PKR " << fixed << setprecision(2) << amount << " transferred from Acc# " << fromAcc << " to Acc# " << toAcc << endl;
    pressEnterToContinue();
}

// ============================================
// FR-A9: View Transaction History
// ============================================

void viewAllTransactions() {
    printHeader("ALL TRANSACTION HISTORY");

    Transaction transactions[MAX_TRANSACTIONS];
    int count = loadAllTransactions(transactions, MAX_TRANSACTIONS);

    if (count == 0) {
        printWarning("No transactions found.");
        pressEnterToContinue();
        return;
    }

    // Table header
    setColor(11);
    cout << "  " << left
         << setw(10) << "Txn ID"
         << setw(10) << "Acc#"
         << setw(16) << "Type"
         << setw(14) << "Amount"
         << "Date/Time" << endl;
    resetColor();
    printLine(70);

    // Print each transaction
    for (int i = 0; i < count; i++) {
        cout << "  " << left
             << setw(10) << transactions[i].transactionID
             << setw(10) << transactions[i].accountNumber
             << setw(16) << transactions[i].type
             << "PKR " << setw(10) << fixed << setprecision(2) << transactions[i].amount
             << transactions[i].dateTime << endl;
    }

    printLine(70);
    setColor(11);
    cout << "  Total Transactions: " << count << endl;
    resetColor();

    pressEnterToContinue();
}

// ============================================
// FR-A10: System Statistics
// ============================================

void showStatistics() {
    printHeader("SYSTEM STATISTICS");

    Customer customers[MAX_CUSTOMERS];
    int custCount = loadAllCustomers(customers, MAX_CUSTOMERS);

    Transaction transactions[MAX_TRANSACTIONS];
    int txnCount = loadAllTransactions(transactions, MAX_TRANSACTIONS);

    // Calculate statistics
    double totalBalance = 0;
    int lockedCount = 0;
    int savingsCount = 0;
    int currentCount = 0;

    for (int i = 0; i < custCount; i++) {
        totalBalance += customers[i].balance;
        if (customers[i].isLocked) lockedCount++;
        if (customers[i].accountType == "Savings") savingsCount++;
        else currentCount++;
    }

    setColor(11);
    cout << "  =================================" << endl;
    cout << "        BANK STATISTICS REPORT      " << endl;
    cout << "  =================================" << endl;
    resetColor();
    cout << endl;
    cout << "  Total Customers       : " << custCount << endl;
    cout << "  Savings Accounts      : " << savingsCount << endl;
    cout << "  Current Accounts      : " << currentCount << endl;
    cout << "  Active Accounts       : " << (custCount - lockedCount) << endl;
    cout << "  Locked Accounts       : " << lockedCount << endl;
    cout << endl;
    setColor(10);
    cout << "  Total Bank Balance    : PKR " << fixed << setprecision(2) << totalBalance << endl;
    resetColor();
    cout << "  Total Transactions    : " << txnCount << endl;
    cout << endl;
    cout << "  Report Generated At   : " << getCurrentDateTime() << endl;

    pressEnterToContinue();
}

// ============================================
// FR-A11: Lock Account
// ============================================

void adminLockAccount() {
    printHeader("LOCK CUSTOMER ACCOUNT");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number to Lock: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);
    if (index == -1) {
        printError("Account not found!");
        pressEnterToContinue();
        return;
    }

    if (customers[index].isLocked) {
        printWarning("Account #" + to_string(accNo) + " is already locked!");
        pressEnterToContinue();
        return;
    }

    cout << "  Customer: " << customers[index].name << endl;

    char confirm;
    cout << "  Are you sure you want to lock this account? (Y/N): ";
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        customers[index].isLocked = true;
        saveAllCustomers(customers, count);
        printSuccess("Account #" + to_string(accNo) + " has been locked.");
    } else {
        printWarning("Lock operation cancelled.");
    }

    pressEnterToContinue();
}

// ============================================
// FR-A11: Unlock Account
// ============================================

void adminUnlockAccount() {
    printHeader("UNLOCK CUSTOMER ACCOUNT");

    Customer customers[MAX_CUSTOMERS];
    int count = loadAllCustomers(customers, MAX_CUSTOMERS);

    int accNo;
    cout << "  Enter Account Number to Unlock: ";
    cin >> accNo;

    int index = findCustomerIndex(customers, count, accNo);
    if (index == -1) {
        printError("Account not found!");
        pressEnterToContinue();
        return;
    }

    if (!customers[index].isLocked) {
        printWarning("Account #" + to_string(accNo) + " is already active!");
        pressEnterToContinue();
        return;
    }

    customers[index].isLocked = false;
    saveAllCustomers(customers, count);
    printSuccess("Account #" + to_string(accNo) + " has been unlocked.");

    pressEnterToContinue();
}
