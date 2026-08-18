// ============================================
// Bank Management System - Admin Module
// ============================================
// Declarations for all admin/manager functions.
// ============================================

#ifndef ADMIN_H
#define ADMIN_H

// ---- Authentication ----
void adminLogin();

// ---- Admin Dashboard ----
void adminMenu();

// ---- Customer Management ----
void addCustomer();
void viewAllCustomers();
void searchCustomer();
void editCustomer();
void deleteCustomer();

// ---- Banking Operations ----
void adminDeposit();
void adminWithdraw();
void adminTransfer();

// ---- Reports ----
void viewAllTransactions();
void showStatistics();

// ---- Account Security ----
void adminLockAccount();
void adminUnlockAccount();

#endif
