#include <iostream>


using namespace std;



int main() {
cout << "=== Question 6: Logical Expressions ===\n\n";

      int A = 2, B = 4, C = 6;

      cout << "  Given: A = " << A << ", B = " << B << ", C = " << C << "\n\n";
      cout << boolalpha; // Print true/false instead of 1/0
      cout << "  A) (A == 4 || B > 2)     => " << (A == 4 || B > 2) << "\n";
      cout << "  B) (6 <= C && A == 3)    => " << (6 <= C && A == 3) << "\n";
      cout << "  C) (1 != B && C != 3)    => " << (1 != B && C != 3) << "\n";
      cout << "  D) (A >= -1 || A <= B)   => " << (A >= -1 || A <= B) << "\n";
      cout << "  E) (!(A > 2))            => " << (!(A > 2)) << "\n";
    return 0;
}

