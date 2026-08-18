// ============================================
// Bank Management System - Utility Functions
// ============================================
// Implementation of helper functions for
// screen control, colors, validation, and
// masked input.
// ============================================

#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "../headers/utils.h"

using namespace std;

// ============================================
// Screen Control Functions
// ============================================

// Clear the entire console screen
void clearScreen() {
    system("cls");
}

// Pause execution until user presses a key
void pressEnterToContinue() {
    cout << endl;
    setColor(8); // Gray color
    cout << "  Press any key to continue...";
    resetColor();
    getch(); // Wait for any key press (from conio.h)
}

// Print a decorative separator line
void printLine(int length) {
    setColor(8); // Gray
    cout << "  ";
    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
    resetColor();
}

// Print a formatted section header with box borders
void printHeader(string title) {
    clearScreen();
    cout << endl;

    int innerWidth = 52;
    int titleLen = (int)title.length();
    int leftPad = (innerWidth - titleLen) / 2;
    int rightPad = innerWidth - titleLen - leftPad;

    setColor(11); // Cyan
    // Top border
    cout << "  +";
    for (int i = 0; i < innerWidth; i++) cout << "-";
    cout << "+" << endl;

    // Title line (centered)
    cout << "  |";
    for (int i = 0; i < leftPad; i++) cout << " ";
    cout << title;
    for (int i = 0; i < rightPad; i++) cout << " ";
    cout << "|" << endl;

    // Bottom border
    cout << "  +";
    for (int i = 0; i < innerWidth; i++) cout << "-";
    cout << "+" << endl;
    resetColor();
    cout << endl;
}

// Print the ASCII art bank logo with professional box borders
void printBankLogo() {
    setColor(11); // Cyan
    cout << endl;
    cout << "  +====================================================+" << endl;
    cout << "  |                                                    |" << endl;
    cout << "  |    $$$$$   $$      $$   $$$$$$                     |" << endl;
    cout << "  |    $$  $$  $$$    $$$  $$                          |" << endl;
    cout << "  |    $$$$$   $$ $$ $ $$   $$$$$                      |" << endl;
    cout << "  |    $$  $$  $$  $$  $$       $$                     |" << endl;
    cout << "  |    $$$$$   $$      $$  $$$$$$                      |" << endl;
    cout << "  |                                                    |" << endl;
    cout << "  |        BANK  MANAGEMENT  SYSTEM                    |" << endl;
    cout << "  |        Your Trusted Banking Partner                |" << endl;
    cout << "  |                                                    |" << endl;
    cout << "  +====================================================+" << endl;
    resetColor();
    cout << endl;
}

// ============================================
// Date / Time
// ============================================

// Get current date and time as formatted string
string getCurrentDateTime() {
    time_t now = time(0);
    char buffer[30];
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// ============================================
// Input Validation Functions
// ============================================

// Validate password: min 8 chars, 1 upper, 1 lower, 1 digit, 1 special char
bool validatePassword(string password) {
    if (password.length() < 8) return false;

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (int i = 0; i < (int)password.length(); i++) {
        char c = password[i];
        if (c >= 'A' && c <= 'Z') hasUpper = true;
        else if (c >= 'a' && c <= 'z') hasLower = true;
        else if (c >= '0' && c <= '9') hasDigit = true;
        else hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Validate ATM PIN: must be exactly 4 digits (1000-9999)
bool validatePIN(int pin) {
    return (pin >= 1000 && pin <= 9999);
}

// ============================================
// Masked Input Functions
// ============================================

// Read password input, displaying * for each character
string maskPasswordInput() {
    string password = "";
    char ch;

    while (true) {
        ch = getch();

        if (ch == 13) { // Enter key
            cout << endl;
            break;
        } else if (ch == 8) { // Backspace
            if (password.length() > 0) {
                password.erase(password.length() - 1);
                cout << "\b \b"; // Erase the * on screen
            }
        } else if (ch >= 32 && ch <= 126) { // Printable ASCII characters
            password += ch;
            cout << "*";
        }
    }

    return password;
}

// Read 4-digit PIN input, displaying * for each digit
int maskPINInput() {
    string pinStr = "";
    char ch;

    while (true) {
        ch = getch();

        if (ch == 13 && pinStr.length() == 4) { // Enter (only if 4 digits entered)
            cout << endl;
            break;
        } else if (ch == 8) { // Backspace
            if (pinStr.length() > 0) {
                pinStr.erase(pinStr.length() - 1);
                cout << "\b \b";
            }
        } else if (ch >= '0' && ch <= '9' && pinStr.length() < 4) { // Only digits, max 4
            pinStr += ch;
            cout << "*";
        }
    }

    // Convert string to integer
    int pin = atoi(pinStr.c_str());
    return pin;
}

// ============================================
// Console Color Functions
// ============================================

// Set console text color using Windows API
// Common colors: 7=White, 8=Gray, 10=Green, 11=Cyan, 12=Red, 14=Yellow
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Reset console text color to default white
void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// Print a success message in green
void printSuccess(string msg) {
    cout << endl;
    setColor(10); // Green
    cout << "  [SUCCESS] " << msg << endl;
    resetColor();
}

// Print an error message in red
void printError(string msg) {
    cout << endl;
    setColor(12); // Red
    cout << "  [ERROR] " << msg << endl;
    resetColor();
}

// Print a warning message in yellow
void printWarning(string msg) {
    cout << endl;
    setColor(14); // Yellow
    cout << "  [WARNING] " << msg << endl;
    resetColor();
}

// ============================================
// Animation & Receipt Functions
// ============================================

// Show a loading screen with progress bar animation (runs once at startup)
void showLoadingScreen() {
    clearScreen();
    cout << endl;
    printBankLogo();

    // Progress bar animation
    setColor(14); // Yellow
    cout << "  Loading System [";
    for (int i = 0; i < 20; i++) {
        cout << "#" << flush;
        Sleep(80);
    }
    cout << "] 100%" << endl;
    resetColor();

    // Module loading messages
    cout << endl;
    setColor(10); // Green
    cout << "  [OK] Admin Module Loaded" << endl;
    Sleep(150);
    cout << "  [OK] Customer Module Loaded" << endl;
    Sleep(150);
    cout << "  [OK] ATM Module Loaded" << endl;
    Sleep(150);
    cout << "  [OK] File System Initialized" << endl;
    Sleep(150);
    cout << "  [OK] Security System Active" << endl;
    Sleep(150);
    resetColor();

    cout << endl;
    setColor(11); // Cyan
    cout << "  System Ready! Welcome to BMS." << endl;
    resetColor();
    Sleep(600);
}

// Show a processing animation with dots
void showProcessing(string msg) {
    cout << endl;
    setColor(14); // Yellow
    cout << "  " << msg;
    for (int i = 0; i < 3; i++) {
        cout << "." << flush;
        Sleep(300);
    }
    cout << " Done!" << endl;
    resetColor();
}

// Print a formatted transaction receipt with box borders
void printReceipt(string type, int accNo, double amount, double newBalance) {
    string dateTime = getCurrentDateTime();

    cout << endl;
    setColor(11); // Cyan
    cout << "  +-----------------------------------------+" << endl;
    cout << "  |         TRANSACTION RECEIPT              |" << endl;
    cout << "  +-----------------------------------------+" << endl;
    resetColor();
    cout << "  |                                         |" << endl;
    cout << "  |  Type         : " << left << setw(24) << type << "|" << endl;
    cout << "  |  Account No.  : " << left << setw(24) << accNo << "|" << endl;
    cout << "  |  Amount       : PKR " << left << setw(20) << fixed << setprecision(2) << amount << "|" << endl;
    cout << "  |  New Balance  : PKR " << left << setw(20) << fixed << setprecision(2) << newBalance << "|" << endl;
    cout << "  |  Date/Time    : " << left << setw(24) << dateTime << "|" << endl;
    cout << "  |                                         |" << endl;
    setColor(11);
    cout << "  +-----------------------------------------+" << endl;
    resetColor();
}
