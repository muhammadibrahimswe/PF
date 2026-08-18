// Problem 4: Batting Strike Rate Calculator
#include <iostream>
using namespace std;

double calculateStrikeRate(int balls, int runs) {
    double strikeRate = ((double)runs / balls) * 100;
    return strikeRate;
}

int main() {
    int balls, runs;
    cout << "Enter Total Runs : ";
    cin >> runs;

    cout << "Enter Total Balls : ";
    cin >> balls;

    cout << "The Strike Rate is : " << calculateStrikeRate(balls, runs);
    return 0;
}
