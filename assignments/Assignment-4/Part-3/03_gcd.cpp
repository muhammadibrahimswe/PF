// Problem 3: Find GCD of Two Numbers
#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int firstNumber, secondNumber;
    cout << "Enter the First Number";
    cin >> firstNumber;
    cout << "Enter the Second Number";
    cin >> secondNumber;

    cout << findGCD(firstNumber, secondNumber);
    return 0;
}
