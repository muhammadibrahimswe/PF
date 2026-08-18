// Problem 3: Custom Power Function
#include <iostream>
using namespace std;

int calculatePower(int base, int exponent) {
    int total = 1;
    for (int i = 1; i <= exponent; i++) {
        total = total * base;
    }
    return total;
}

int main() {
    int base, exponent;
    cout << "Enter the Base : ";
    cin >> base;
    cout << "Enter the Exponent : ";
    cin >> exponent;

    cout << "The Final Result is : " << calculatePower(base, exponent);
    return 0;
}
