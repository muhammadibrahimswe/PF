#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

