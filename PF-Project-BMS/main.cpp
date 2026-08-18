// ============================================
// Bank Management System (BMS) - Main Entry
// ============================================
// This is the main entry point of the program.
// It displays the bank logo, main menu, and
// routes to the appropriate module.
// ============================================

#include <iostream>
#include <string>
#include "headers/structs.h"
#include "headers/globals.h"
#include "headers/utils.h"
#include "headers/admin.h"
#include "headers/customer.h"
#include "headers/atm.h"

using namespace std;

int main() {
    // Show loading screen on startup
    showLoadingScreen();

    int choice;

    do {
        clearScreen();
        printBankLogo();

        // Display current date/time
        setColor(8); // Gray
        cout << "  " << getCurrentDateTime() << endl;
        resetColor();
        cout << endl;

        // Main Menu
        printLine(50);
        setColor(11); // Cyan
        cout << "               MAIN MENU" << endl;
        resetColor();
        printLine(50);
        cout << endl;

        setColor(14); // Yellow
        cout << "  [1] Admin / Manager Login" << endl;
        cout << "  [2] Customer Section" << endl;
        cout << "  [3] ATM Section" << endl;
        cout << "  [0] Exit System" << endl;
        resetColor();

        cout << endl;
        cout << "  Enter Your Choice: ";
        cin >> choice;

        // Handle invalid (non-numeric) input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                atmSection();
                break;
            case 0:
                // Exit message
                clearScreen();
                printBankLogo();
                setColor(10); // Green
                cout << "  Thank you for using Bank Management System!" << endl;
                cout << "  Have a great day. Goodbye!" << endl;
                resetColor();
                cout << endl;
                break;
            default:
                printError("Invalid choice! Please enter a valid option.");
                pressEnterToContinue();
        }
    } while (choice != 0);

    return 0;
}







/*

for compiling =  g++ -o bms.exe main.cpp modules/utils.cpp modules/filehandling.cpp modules/admin.cpp modules/customer.cpp modules/atm.cpp 

for running =  ./bms.exe

*/