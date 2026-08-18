#include <iostream>


using namespace std;



int main() {
cout << "=== Question 14: Magic Date ===\n\n";

      int month, day, year;
      cout << "  Enter month (1-12):       ";
      cin >> month;
      cout << "  Enter day:                ";
      cin >> day;
      cout << "  Enter two-digit year:     ";
      cin >> year;

      // A "magic" date is when month * day equals the two-digit year
      if (month * day == year)
        cout << "\n  The date IS magic!\n";
      else
        cout << "\n  The date is NOT magic.\n";
    return 0;
}

