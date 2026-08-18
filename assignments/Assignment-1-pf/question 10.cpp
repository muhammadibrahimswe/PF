#include <iostream>


using namespace std;

const double GRAVITY = 9.8;         // Acceleration due to gravity (m/s^2)


int main() {
cout << "=== Question 10: Weight Calculator ===\n\n";

      double mass;
      cout << "  Enter object's mass (kg): ";
      cin >> mass;

      double weight = mass * GRAVITY;
      cout << "  Weight = " << weight << " Newtons\n";

      // Classify the weight
      if (weight > 1000.0)
        cout << "  Status: The object is too heavy.\n";
      else if (weight < 10.0)
        cout << "  Status: The object is too light.\n";
      else
        cout << "  Status: The object weight is normal.\n";
    return 0;
}

