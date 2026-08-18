#include <iostream>


using namespace std;



int main() {
cout << "=== Question 2: Temperature Validation ===\n\n";

      double temperature = 75.5; // Example hardcoded value

      cout << "  Temperature = " << temperature << "\n";

      // Check if temperature is within a valid range
      if (temperature >= -50.0 && temperature <= 150.0)
        cout << "  Result: The number is VALID.\n";
      else
        cout << "  Result: The number is INVALID.\n";
    return 0;
}

