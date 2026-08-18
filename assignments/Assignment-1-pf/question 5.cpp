#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

