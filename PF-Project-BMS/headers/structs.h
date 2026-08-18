// ============================================
// Bank Management System - Data Structures
// ============================================
// This file defines the core structs used
// throughout the BMS project.
// ============================================

#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
using namespace std;

// Stores all information about a single customer account
struct Customer {
    int accountNumber;
    string name;
    string cnic;
    string phone;
    string address;
    string password;
    int pin;            // 4-digit ATM PIN
    double balance;
    string accountType; // "Savings" or "Current"
    bool isLocked;      // true = account is locked
};

// Stores a single transaction record
struct Transaction {
    int transactionID;
    int accountNumber;
    string type;        // "Deposit", "Withdrawal", "Transfer-Out", "Transfer-In", "ATM-Withdrawal", "ATM-FastCash"
    double amount;
    string dateTime;    // Format: "YYYY-MM-DD HH:MM:SS"
};

#endif
