// ============================================
// Bank Management System - Customer Module
// ============================================
// Declarations for customer registration,
// login, and banking operations.
// ============================================

#ifndef CUSTOMER_H
#define CUSTOMER_H

// ---- Customer Section Menu ----
void customerMenu();

// ---- Registration & Login ----
void registerCustomer();
void loginCustomer();

// ---- Customer Dashboard ----
void customerDashboard(int accountNumber);

// ---- Account Operations ----
void viewProfile(int accountNumber);
void checkBalance(int accountNumber);
void customerDeposit(int accountNumber);
void customerWithdraw(int accountNumber);
void customerTransfer(int accountNumber);
void changePassword(int accountNumber);
void viewMyTransactions(int accountNumber);

#endif
