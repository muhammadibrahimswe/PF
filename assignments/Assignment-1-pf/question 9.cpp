#include <iostream>


using namespace std;



int main() {
cout << "=== Question 9: ASCII Values of Alphabets ===\n\n";

      // Uppercase letters A-Z
      cout << "  Uppercase A-Z:\n  ";
      for (char ch = 'A'; ch <= 'Z'; ++ch) {
        cout << ch << "=" << static_cast<int>(ch) << "  ";
      }

      // Lowercase letters a-z
      cout << "\n\n  Lowercase a-z:\n  ";
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        cout << ch << "=" << static_cast<int>(ch) << "  ";
      }
      cout << "\n";

    return 0;
}

