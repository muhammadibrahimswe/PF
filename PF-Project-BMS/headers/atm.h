// ============================================
// Bank Management System - ATM Module
// ============================================
// Declarations for ATM authentication and
// ATM banking operations.
// ============================================

#ifndef ATM_H
#define ATM_H

// ---- ATM Entry (Login with PIN) ----
void atmSection();

// ---- ATM Dashboard ----
void atmMenu(int accountNumber);

// ---- ATM Operations ----
void balanceInquiry(int accountNumber);
void cashWithdrawal(int accountNumber);
void fastCash(int accountNumber);
void miniStatement(int accountNumber);
void changePin(int accountNumber);

#endif
