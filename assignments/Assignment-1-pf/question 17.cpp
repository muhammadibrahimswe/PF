#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

