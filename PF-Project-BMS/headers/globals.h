// ============================================
// Bank Management System - Global Constants
// ============================================
// This file defines all constants and
// configuration values used in the system.
// ============================================

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
using namespace std;

// ---- Admin Credentials (Hardcoded) ----
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "Admin@123";

// ---- Security Settings ----
const int MAX_LOGIN_ATTEMPTS = 3;

// ---- Array Size Limits ----
const int MAX_CUSTOMERS = 100;
const int MAX_TRANSACTIONS = 1000;

// ---- File Paths ----
const string CUSTOMERS_FILE = "customers.txt";
const string TRANSACTIONS_FILE = "transactions.txt";

#endif
