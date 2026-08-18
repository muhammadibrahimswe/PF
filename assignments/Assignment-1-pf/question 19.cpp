#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

