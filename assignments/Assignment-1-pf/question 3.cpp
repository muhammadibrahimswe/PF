#include <iostream>


using namespace std;



int main() {
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
    return 0;
}

