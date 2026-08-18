// Problem 4: Voltage Calculator
#include <iostream>
using namespace std;

double calculateVoltage(double current, double resistance) {
    return current * resistance;
}

int main() {
    double current, resistance;
    cout << "Enter the Value Of Current : ";
    cin >> current;
    cout << "Enter the Value Of resistance : ";
    cin >> resistance;

    cout << "The Voltage is " << calculateVoltage(current, resistance);
    return 0;
}
