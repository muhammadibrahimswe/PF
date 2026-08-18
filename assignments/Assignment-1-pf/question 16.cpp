#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

