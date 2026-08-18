// ============================================
// Bank Management System - File Handling
// ============================================
// Implementation of all file I/O operations.
// Uses pipe-delimited (|) text files for
// simple, human-readable data storage.
// ============================================
//
// File Formats:
// customers.txt:    accNo|name|cnic|phone|address|password|pin|balance|accountType|isLocked
// transactions.txt: txnID|accNo|type|amount|dateTime
// ============================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "../headers/filehandling.h"
#include "../headers/globals.h"

using namespace std;

// ============================================
// Customer File Operations
// ============================================

// Append a single customer record to the file
void saveCustomer(Customer c) {
    ofstream file(CUSTOMERS_FILE.c_str(), ios::app);
    if (file.is_open()) {
        file << c.accountNumber << "|"
             << c.name << "|"
             << c.cnic << "|"
             << c.phone << "|"
             << c.address << "|"
             << c.password << "|"
             << c.pin << "|"
             << fixed << setprecision(2) << c.balance << "|"
             << c.accountType << "|"
             << c.isLocked << endl;
        file.close();
    }
}

// Rewrite the entire customers file with the given array
void saveAllCustomers(Customer arr[], int count) {
    ofstream file(CUSTOMERS_FILE.c_str()); // Overwrites file
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << arr[i].accountNumber << "|"
                 << arr[i].name << "|"
                 << arr[i].cnic << "|"
                 << arr[i].phone << "|"
                 << arr[i].address << "|"
                 << arr[i].password << "|"
                 << arr[i].pin << "|"
                 << fixed << setprecision(2) << arr[i].balance << "|"
                 << arr[i].accountType << "|"
                 << arr[i].isLocked << endl;
        }
        file.close();
    }
}

// Load all customer records from file into an array
// Returns the number of customers loaded
int loadAllCustomers(Customer arr[], int maxSize) {
    ifstream file(CUSTOMERS_FILE.c_str());
    int count = 0;
    string line;

    if (file.is_open()) {
        while (getline(file, line) && count < maxSize) {
            // Skip empty lines
            if (line.empty()) continue;

            stringstream ss(line);
            string token;

            // Read account number
            getline(ss, token, '|');
            arr[count].accountNumber = atoi(token.c_str());

            // Read string fields
            getline(ss, arr[count].name, '|');
            getline(ss, arr[count].cnic, '|');
            getline(ss, arr[count].phone, '|');
            getline(ss, arr[count].address, '|');
            getline(ss, arr[count].password, '|');

            // Read PIN
            getline(ss, token, '|');
            arr[count].pin = atoi(token.c_str());

            // Read balance
            getline(ss, token, '|');
            arr[count].balance = atof(token.c_str());

            // Read account type
            getline(ss, arr[count].accountType, '|');

            // Read isLocked (last field, no trailing delimiter)
            getline(ss, token);
            arr[count].isLocked = (token == "1");

            count++;
        }
        file.close();
    }

    return count;
}

// ============================================
// Transaction File Operations
// ============================================

// Append a single transaction record to the file
void saveTransaction(Transaction t) {
    ofstream file(TRANSACTIONS_FILE.c_str(), ios::app);
    if (file.is_open()) {
        file << t.transactionID << "|"
             << t.accountNumber << "|"
             << t.type << "|"
             << fixed << setprecision(2) << t.amount << "|"
             << t.dateTime << endl;
        file.close();
    }
}

// Load all transaction records from file into an array
// Returns the number of transactions loaded
int loadAllTransactions(Transaction arr[], int maxSize) {
    ifstream file(TRANSACTIONS_FILE.c_str());
    int count = 0;
    string line;

    if (file.is_open()) {
        while (getline(file, line) && count < maxSize) {
            if (line.empty()) continue;

            stringstream ss(line);
            string token;

            // Read transaction ID
            getline(ss, token, '|');
            arr[count].transactionID = atoi(token.c_str());

            // Read account number
            getline(ss, token, '|');
            arr[count].accountNumber = atoi(token.c_str());

            // Read type
            getline(ss, arr[count].type, '|');

            // Read amount
            getline(ss, token, '|');
            arr[count].amount = atof(token.c_str());

            // Read dateTime (last field)
            getline(ss, arr[count].dateTime);

            count++;
        }
        file.close();
    }

    return count;
}

// ============================================
// ID Generator Functions
// ============================================

// Find the highest account number in the file and return next one
// Accounts start from 1001
int getNextAccountNumber() {
    ifstream file(CUSTOMERS_FILE.c_str());
    int maxAcc = 1000; // Starting base (first account will be 1001)
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string token;
            getline(ss, token, '|');
            int accNo = atoi(token.c_str());
            if (accNo > maxAcc) maxAcc = accNo;
        }
        file.close();
    }

    return maxAcc + 1;
}

// Find the highest transaction ID in the file and return next one
// Transaction IDs start from 10001
int getNextTransactionID() {
    ifstream file(TRANSACTIONS_FILE.c_str());
    int maxID = 10000; // Starting base (first txn will be 10001)
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string token;
            getline(ss, token, '|');
            int id = atoi(token.c_str());
            if (id > maxID) maxID = id;
        }
        file.close();
    }

    return maxID + 1;
}

// ============================================
// Search Helper Functions
// ============================================

// Find a customer by account number in the array
// Returns the array index, or -1 if not found
int findCustomerIndex(Customer arr[], int count, int accountNumber) {
    for (int i = 0; i < count; i++) {
        if (arr[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

// Find a customer by CNIC in the array
// Returns the array index, or -1 if not found
int findCustomerByCNIC(Customer arr[], int count, string cnic) {
    for (int i = 0; i < count; i++) {
        if (arr[i].cnic == cnic) {
            return i;
        }
    }
    return -1;
}
