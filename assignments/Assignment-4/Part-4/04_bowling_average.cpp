// Problem 4: Bowling Average Calculator
#include <iostream>
using namespace std;

double bowlingAverage(int runs, int wickets) {
    if (wickets == 0) {
        return 0;
    }
    return (double)runs / wickets;
}

int main() {
    int runs, wickets;
    cout << "Enter Runs Conceded: ";
    cin >> runs;
    cout << "Enter Wickets Taken: ";
    cin >> wickets;

    double average = bowlingAverage(runs, wickets);
    cout << "Average: " << average << endl;
    return 0;
}
