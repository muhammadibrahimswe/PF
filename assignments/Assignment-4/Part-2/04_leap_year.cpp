// Problem 4: Leap Year Checker
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

int main() {
    int leapYear;
    cout << "Enter Leap Year :";
    cin >> leapYear;

    if (isLeapYear(leapYear)) {
        cout << leapYear << " Is a Leap Year";
    } else {
        cout << leapYear << " Not a Leap Year";
    }
    return 0;
}
