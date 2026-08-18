// ============================================
// Bank Management System - File Handling
// ============================================
// Declarations for all file I/O operations:
// save, load, search helpers for customers
// and transactions.
// ============================================

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <string>
#include "structs.h"
using namespace std;

// ---- Customer File Operations ----
void saveCustomer(Customer c);
void saveAllCustomers(Customer arr[], int count);
int loadAllCustomers(Customer arr[], int maxSize);

// ---- Transaction File Operations ----
void saveTransaction(Transaction t);
int loadAllTransactions(Transaction arr[], int maxSize);

// ---- ID Generators ----
int getNextAccountNumber();
int getNextTransactionID();

// ---- Search Helpers ----
int findCustomerIndex(Customer arr[], int count, int accountNumber);
int findCustomerByCNIC(Customer arr[], int count, string cnic);

#endif
