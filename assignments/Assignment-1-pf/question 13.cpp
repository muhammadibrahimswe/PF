#include <iostream>


using namespace std;



int main() {
 cout << "=== Question 13: TV Models ===\n\n";

      int model;
      cout << "  1. Model 300\n";
      cout << "  2. Model 200\n";
      cout << "  3. Model 100\n";
      cout << "  Enter choice (1-3): ";
      cin >> model;

      // Each higher model includes all features of lower models
      if (model == 1)
        cout << "  Model 300: Picture-in-Picture, Stereo Sound, Remote "
                "Control\n";
      else if (model == 2)
        cout << "  Model 200: Stereo Sound, Remote Control\n";
      else if (model == 3)
        cout << "  Model 100: Remote Control only\n";
      else
        cout << "  [!] Invalid model selected.\n";
    return 0;
}

