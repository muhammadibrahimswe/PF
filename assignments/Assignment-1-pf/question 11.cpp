#include <iostream>


using namespace std;



int main() {
cout << "=== Question 11: Sales Bonus ===\n\n";

      double sales = 60000.0;
      double total = sales;

      // If sales exceed $50,000 ? apply 25% bonus + $250 flat bonus
      if (sales > 50000.0) {
        total += (sales * 0.25) + 250.0;
      }

      cout << "  Sales:  $" << sales << "\n";
      cout << "  Total after bonus: $" << total << "\n";
    return 0;
}

