#include <iostream>


using namespace std;



int main() {
cout << "=== Question 20: Seconds Converter ===\n\n";

      long long seconds;
      cout << "  Enter number of seconds: ";
      cin >> seconds;

      // Convert to the largest applicable time unit
      if (seconds >= 86400)
        cout << "  " << seconds / 86400 << " day(s)\n";
      else if (seconds >= 3600)
        cout << "  " << seconds / 3600 << " hour(s)\n";
      else if (seconds >= 60)
        cout << "  " << seconds / 60 << " minute(s)\n";
      else
        cout << "  " << seconds << " second(s)\n";
    return 0;
}

