#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

