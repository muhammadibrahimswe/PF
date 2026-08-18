#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

