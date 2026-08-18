// ============================================
// Bank Management System - Utility Functions
// ============================================
// Declarations for helper functions:
// screen control, colors, validation, input masking
// ============================================

#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

// ---- Screen Control ----
void clearScreen();
void pressEnterToContinue();
void printHeader(string title);
void printBankLogo();
void printLine(int length = 60);

// ---- Date/Time ----
string getCurrentDateTime();

// ---- Input Validation ----
bool validatePassword(string password);
bool validatePIN(int pin);

// ---- Masked Input ----
string maskPasswordInput();
int maskPINInput();

// ---- Console Colors ----
void setColor(int color);
void resetColor();
void printSuccess(string msg);
void printError(string msg);
void printWarning(string msg);

// ---- Animations & Receipts ----
void showLoadingScreen();
void showProcessing(string msg);
void printReceipt(string type, int accNo, double amount, double newBalance);

#endif
