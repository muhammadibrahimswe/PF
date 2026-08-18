#include <cctype>   // tolower()
#include <iomanip>  // fixed, setprecision
#include <iostream> // cin, cout

using namespace std;

// --- Constants ---------------------------------------------------------------
const double PI = 3.14159265358979; // Mathematical constant pi
const double GRAVITY = 9.8;         // Acceleration due to gravity (m/s^2)

// =============================================================================
//                                MAIN FUNCTION
// =============================================================================
int main() {
  // Set floating-point output to 2 decimal places globally
  cout << fixed << setprecision(2);

  bool running = true; // Controls the main program loop
  int menuChoice;      // Stores the user's menu selection
  char continueChoice; // Stores Y/N to continue or exit

  // ========================= MAIN PROGRAM LOOP =============================
  while (running) {

    // --- Display Main Menu -------------------------------------------
    cout << "\n\n";
    cout << "==========================================\n";
    cout << "   C++ ASSIGNMENT - MENU     \n";
    cout << "==========================================\n";

    for (int i = 1; i <= 20; ++i) {
      cout << "  " << i << ". Question " << i << "\n";
    }

    cout << "  \n  21. Exit Program\n";
    cout << "==========================================\n";
    cout << "  Enter your choice (1-21): ";
    cin >> menuChoice;

    // --- Exit Check --------------------------------------------------
    if (menuChoice == 21) {
      break; // Breaking condition of While loop & Makes the Progrom Ends
    }

    // --- Invalid Input Guard -----------------------------------------
    if (menuChoice < 1 || menuChoice > 20) {
      cout << "\n  [!] Invalid choice. Please enter a number between 1 and "
              "21.\n";
      continue; // Restart the loop
    }

    // --- Header for Selected Question --------------------------------
    cout << "\n\n";
    cout << "==========================================\n";
    cout << "      EXECUTING QUESTION " << menuChoice << "\n";
    cout << "==========================================\n\n";

    // =====================================================================
    //                        QUESTION DISPATCHER
    // =====================================================================
    switch (menuChoice) {

    // -----------------------------------------------------------------
    // QUESTION 1: Simple if-else with integer comparison
    // -----------------------------------------------------------------
    case 1: {
      cout << "=== Question 1: If-Else Demo ===\n\n";

      int y = 10;
      int x;

      // Assign x based on the value of y
      if (y == 10)
        x = 0;
      else
        x = 1;

      cout << "  y = " << y << "\n";
      cout << "  x = " << x << "\n";
      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 2: Range validation for temperature
    // -----------------------------------------------------------------
    case 2: {
      cout << "=== Question 2: Temperature Validation ===\n\n";

      double temperature = 75.5; // Example hardcoded value

      cout << "  Temperature = " << temperature << "\n";

      // Check if temperature is within a valid range
      if (temperature >= -50.0 && temperature <= 150.0)
        cout << "  Result: The number is VALID.\n";
      else
        cout << "  Result: The number is INVALID.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 3: Compare two numbers (smaller / larger)
    // -----------------------------------------------------------------
    case 3: {
      cout << "=== Question 3: Compare Two Numbers ===\n\n";

      double num1, num2;
      cout << "  Enter first number:  ";
      cin >> num1;
      cout << "  Enter second number: ";
      cin >> num2;

      // Determine which number is smaller / larger
      if (num1 < num2)
        cout << "  " << num1 << " is smaller and " << num2 << " is larger.\n";
      else if (num2 < num1)
        cout << "  " << num2 << " is smaller and " << num1 << " is larger.\n";
      else
        cout << "  Both numbers are equal.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 4: Floating-point arithmetic comparison
    // -----------------------------------------------------------------
    case 4: {
      cout << "=== Question 4: Float Comparison ===\n\n";

      double a = 10.0;
      double b = 10.0;
      a += 0.2; // a becomes 10.2

      cout << "  a = " << a << ",  b = " << b << "\n";

      // Compare after modification
      if (a > b)
        cout << "  a is larger than b.\n";
      else if (b > a)
        cout << "  b is larger than a.\n";
      else
        cout << "  Both are equal.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 5: Division with zero-check
    // -----------------------------------------------------------------
    case 5: {
      cout << "=== Question 5: Safe Division ===\n\n";

      double numerator, denominator;
      cout << "  Enter numerator:   ";
      cin >> numerator;
      cout << "  Enter denominator: ";
      cin >> denominator;

      // Guard against division by zero
      if (denominator != 0.0)
        cout << "  Result = " << (numerator / denominator) << "\n";
      else
        cout << "  [!] Division by zero is not possible.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 6: Boolean / logical expression evaluation
    // -----------------------------------------------------------------
    case 6: {
      cout << "=== Question 6: Logical Expressions ===\n\n";

      int A = 2, B = 4, C = 6;

      cout << "  Given: A = " << A << ", B = " << B << ", C = " << C << "\n\n";
      cout << boolalpha; // Print true/false instead of 1/0
      cout << "  A) (A == 4 || B > 2)     => " << (A == 4 || B > 2) << "\n";
      cout << "  B) (6 <= C && A == 3)    => " << (6 <= C && A == 3) << "\n";
      cout << "  C) (1 != B && C != 3)    => " << (1 != B && C != 3) << "\n";
      cout << "  D) (A >= -1 || A <= B)   => " << (A >= -1 || A <= B) << "\n";
      cout << "  E) (!(A > 2))            => " << (!(A > 2)) << "\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 7: Determine the fastest runner from three times
    // -----------------------------------------------------------------
case 7: {
    cout << "=== Question 7: Runners Ranking (1st, 2nd & 3rd Place) ===\n\n";

    double time1, time2, time3;

    cout << "Enter time for Runner 1 (seconds): ";
    cin >> time1;
    cout << "Enter time for Runner 2 (seconds): ";
    cin >> time2;
    cout << "Enter time for Runner 3 (seconds): ";
    cin >> time3;

    cout << "\n--- Race Results ---\n";

    // Finding 1st, 2nd and 3rd using if-else logic

    if (time1 <= time2 && time1 <= time3) {           // Runner 1 is First
        cout << "1st Place: Runner 1 (" << time1 << "s)\n";
        
        if (time2 <= time3) {
            cout << "2nd Place: Runner 2 (" << time2 << "s)\n";
            cout << "3rd Place: Runner 3 (" << time3 << "s)\n";
        } else {
            cout << "2nd Place: Runner 3 (" << time3 << "s)\n";
            cout << "3rd Place: Runner 2 (" << time2 << "s)\n";
        }
    }
    else if (time2 <= time1 && time2 <= time3) {      // Runner 2 is First
        cout << "1st Place: Runner 2 (" << time2 << "s)\n";
        
        if (time1 <= time3) {
            cout << "2nd Place: Runner 1 (" << time1 << "s)\n";
            cout << "3rd Place: Runner 3 (" << time3 << "s)\n";
        } else {
            cout << "2nd Place: Runner 3 (" << time3 << "s)\n";
            cout << "3rd Place: Runner 1 (" << time1 << "s)\n";
        }
    }
    else {                                            // Runner 3 is First
        cout << "1st Place: Runner 3 (" << time3 << "s)\n";
        
        if (time1 <= time2) {
            cout << "2nd Place: Runner 1 (" << time1 << "s)\n";
            cout << "3rd Place: Runner 2 (" << time2 << "s)\n";
        } else {
            cout << "2nd Place: Runner 2 (" << time2 << "s)\n";
            cout << "3rd Place: Runner 1 (" << time1 << "s)\n";
        }
    }

    break;
}

    // -----------------------------------------------------------------
    // QUESTION 8: Geometry area calculator (Circle / Rectangle / Triangle)
    // -----------------------------------------------------------------
    case 8: {
      cout << "=== Question 8: Geometry Calculator ===\n\n";

      int shapeChoice;
      cout << "  1. Calculate the Area of a Circle\n";
      cout << "  2. Calculate the Area of a Rectangle\n";
      cout << "  3. Calculate the Area of a Triangle\n";
      cout << "  Enter your choice (1-3): ";
      cin >> shapeChoice;

      if (shapeChoice == 1) {
        double radius;
        cout << "  Enter radius: ";
        cin >> radius;
        cout << "  Area of Circle = " << PI * radius * radius << "\n";
      } else if (shapeChoice == 2) {
        double length, width;
        cout << "  Enter length: ";
        cin >> length;
        cout << "  Enter width:  ";
        cin >> width;
        cout << "  Area of Rectangle = " << length * width << "\n";
      } else if (shapeChoice == 3) {
        double base, height;
        cout << "  Enter base:   ";
        cin >> base;
        cout << "  Enter height: ";
        cin >> height;
        cout << "  Area of Triangle = " << (base * height * 0.5) << "\n";
      } else {
        cout << "  [!] Invalid choice.\n";
      }

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 9: Print ASCII values for all alphabets
    // -----------------------------------------------------------------
    case 9: {
      cout << "=== Question 9: ASCII Values of Alphabets ===\n\n";

      // Uppercase letters A-Z
      cout << "  Uppercase A-Z:\n  ";
      for (char ch = 'A'; ch <= 'Z'; ++ch) {
        cout << ch << "=" << static_cast<int>(ch) << "  ";
      }

      // Lowercase letters a-z
      cout << "\n\n  Lowercase a-z:\n  ";
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        cout << ch << "=" << static_cast<int>(ch) << "  ";
      }
      cout << "\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 10: Weight calculator (mass * gravity)
    // -----------------------------------------------------------------
    case 10: {
      cout << "=== Question 10: Weight Calculator ===\n\n";

      double mass;
      cout << "  Enter object's mass (kg): ";
      cin >> mass;

      double weight = mass * GRAVITY;
      cout << "  Weight = " << weight << " Newtons\n";

      // Classify the weight
      if (weight > 1000.0)
        cout << "  Status: The object is too heavy.\n";
      else if (weight < 10.0)
        cout << "  Status: The object is too light.\n";
      else
        cout << "  Status: The object weight is normal.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 11: Sales bonus calculation
    // -----------------------------------------------------------------
    case 11: {
      cout << "=== Question 11: Sales Bonus ===\n\n";

      double sales = 60000.0;
      double total = sales;

      // If sales exceed $50,000 ? apply 25% bonus + $250 flat bonus
      if (sales > 50000.0) {
        total += (sales * 0.25) + 250.0;
      }

      cout << "  Sales:  $" << sales << "\n";
      cout << "  Total after bonus: $" << total << "\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 12: Loan qualification checker
    // -----------------------------------------------------------------
    case 12: {
      cout << "=== Question 12: Loan Qualification ===\n\n";

      double income;
      int years;

      cout << "  Enter annual income: $";
      cin >> income;
      cout << "  Enter years at current job: ";
      cin >> years;

      // Qualify if income >= $35,000 AND employed > 5 years
      if (income >= 35000.0 && years > 5)
        cout << "\n  [APPROVED] You qualify for the special loan!\n";
      else
        cout << "\n  [DENIED] You do not qualify for the special loan.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 13: TV model features (cascading if-else)
    // -----------------------------------------------------------------
    case 13: {
      cout << "=== Question 13: TV Models ===\n\n";

      int model;
      cout << "  1. Model 300\n";
      cout << "  2. Model 200\n";
      cout << "  3. Model 100\n";
      cout << "  Enter choice (1-3): ";
      cin >> model;

      // Each higher model includes all features of lower models
      if (model == 1)
        cout << "  Model 300: Picture-in-Picture, Stereo Sound, Remote "
                "Control\n";
      else if (model == 2)
        cout << "  Model 200: Stereo Sound, Remote Control\n";
      else if (model == 3)
        cout << "  Model 100: Remote Control only\n";
      else
        cout << "  [!] Invalid model selected.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 14: Magic date checker (month * day == year?)
    // -----------------------------------------------------------------
    case 14: {
      cout << "=== Question 14: Magic Date ===\n\n";

      int month, day, year;
      cout << "  Enter month (1-12):       ";
      cin >> month;
      cout << "  Enter day:                ";
      cin >> day;
      cout << "  Enter two-digit year:     ";
      cin >> year;

      // A "magic" date is when month * day equals the two-digit year
      if (month * day == year)
        cout << "\n  The date IS magic!\n";
      else
        cout << "\n  The date is NOT magic.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 15: Tiered commission rate calculator
    // -----------------------------------------------------------------
    case 15: {
      cout << "=== Question 15: Commission Rate ===\n\n";

      double salesAmount, commission;
      cout << "  Enter sales amount: $";
      cin >> salesAmount;

      // Tiered commission structure
      if (salesAmount <= 10000.0)
        commission = salesAmount * 0.10; // 10% for up to $10k
      else if (salesAmount <= 15000.0)
        commission = salesAmount * 0.15; // 15% for up to $15k
      else
        commission = salesAmount * 0.20; // 20% for above $15k

      cout << "  Commission = $" << commission << "\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 16: Bank service fees with check tiers
    // -----------------------------------------------------------------
    case 16: {
      cout << "=== Question 16: Bank Service Fees ===\n\n";

      double balance;
      int checks;

      cout << "  Enter beginning balance: $";
      cin >> balance;
      cout << "  Enter number of checks written: ";
      cin >> checks;

      // Calculate per-check fee based on number of checks
      double checkFee = 0.0;
      if (checks < 20)
        checkFee = checks * 0.10;
      else if (checks < 40)
        checkFee = checks * 0.08;
      else if (checks < 60)
        checkFee = checks * 0.06;
      else
        checkFee = checks * 0.04;

      // Base fee is $10 + check fees
      double serviceFee = 10.0 + checkFee;

      // Penalty for low balance (below $400)
      if (balance < 400.0)
        serviceFee += 15.0;

      cout << "\n  Total service fees for the month: $" << serviceFee << "\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 17: Headphone price lookup
    // -----------------------------------------------------------------
    case 17: {
      cout << "=== Question 17: Headphones ===\n\n";

      int headphoneChoice;
      cout << "  1. Noise Canceling  - $249.00\n";
      cout << "  2. Wireless         - $199.00\n";
      cout << "  3. Wired Budget     - $49.00\n";
      cout << "  Enter choice (1-3): ";
      cin >> headphoneChoice;

      if (headphoneChoice == 1)
        cout << "  Price: $249.00\n";
      else if (headphoneChoice == 2)
        cout << "  Price: $199.00\n";
      else if (headphoneChoice == 3)
        cout << "  Price: $49.00\n";
      else
        cout << "  [!] Invalid choice.\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 18: Health club membership cost calculator
    // -----------------------------------------------------------------
    case 18: {
      cout << "=== Question 18: Health Club Membership ===\n\n";

      int membershipChoice, months;
      cout << "  1. Standard Adult  - Rs. 40.00/month\n";
      cout << "  2. Child           - Rs. 20.00/month\n";
      cout << "  3. Senior Citizen  - Rs. 30.00/month\n";
      cout << "  4. Quit\n";
      cout << "  Enter your choice: ";
      cin >> membershipChoice;

      if (membershipChoice >= 1 && membershipChoice <= 3) {
        cout << "  Enter number of months: ";
        cin >> months;
        
        if(months !=0){
		
        // Determine rate based on membership type
        double rate = (membershipChoice == 1)   ? 40.0
                      : (membershipChoice == 2) ? 20.0
                                                : 30.0;

        cout << "  Total amount to pay: Rs. " << rate * months << "\n";}
        else 
        cout << " Process Terminated!  Choose atleast one month for the Process to Continue" << endl;
      } else if (membershipChoice == 4) {
        cout << "  Thank you for using the program.\n";
      } else {
        cout << "  [!] Invalid choice.\n";
      }

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 19: Mobile data plan billing calculator
    // -----------------------------------------------------------------
    case 19: {
      cout << "=== Question 19: Mobile Data Plans ===\n\n";

      int package;
      double gbUsed;
      double totalBill = 0.0;

      cout << "  Enter the package purchased (1, 2, or 3): ";
      cin >> package;
      cout << "  Enter the number of gigabytes used: ";
      cin >> gbUsed;

      // Calculate bill based on package type + overage charges
      if (package == 1) {
        totalBill = 39.99; // Base: $39.99
        if (gbUsed > 4.0)
          totalBill += (gbUsed - 4.0) * 10.0; // $10/GB over 4GB
      } else if (package == 2) {
        totalBill = 59.99; // Base: $59.99
        if (gbUsed > 8.0)
          totalBill += (gbUsed - 8.0) * 5.0; // $5/GB over 8GB
      } else if (package == 3) {
        totalBill = 69.99; // Flat: $69.99
      } else {
        cout << "  [!] Invalid package.\n";
      }

      // Display bill only for valid packages
      if (package >= 1 && package <= 3)
        cout << "  The total amount due is: $" << totalBill << "\n";

      break;
    }

    // -----------------------------------------------------------------
    // QUESTION 20: Convert seconds to the largest time unit
    // -----------------------------------------------------------------
    case 20: {
      cout << "=== Question 20: Seconds Converter ===\n\n";

      long long seconds;
      cout << "  Enter number of seconds: ";
      cin >> seconds;

      // Convert to the largest applicable time unit
      if (seconds >= 86400)
        cout << "  " << seconds / 86400 << " day(s)\n";
      else if (seconds >= 3600)
        cout << "  " << seconds / 3600 << " hour(s)\n";
      else if (seconds >= 60)
        cout << "  " << seconds / 60 << " minute(s)\n";
      else
        cout << "  " << seconds << " second(s)\n";

      break;
    }

    // --- Default Case (should not be reached) ------------------------
    default: {
      cout << "  [!] Unexpected error.\n";
      break;
    }

    } // end switch

    // =====================================================================
    //                     POST-QUESTION PROMPT
    // =====================================================================
    cout << "\n==========================================\n";
    cout << "  Return to main menu? (Y/N): ";
    cin >> continueChoice;

    if (tolower(continueChoice) != 'y') {
      running = false;
    }

  } // end while

  // ========================= GOODBYE MESSAGE ===============================
  cout << "\n==========================================\n";
  cout << "  Thank you for using the C++ Assignment!\n";
  cout << "  Goodbye!\n";
  cout << "==========================================\n";

  return 0;
}
