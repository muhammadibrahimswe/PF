#include <iostream>


using namespace std;



int main() {
cout << "=== Question 7: Runners Ranking (1st, 2nd & 3rd Place) ===\n\n";

    double time1, time2, time3;

    cout << "Enter time for Runner 1 (seconds): ";
    cin >> time1;
    cout << "Enter time for Runner 2 (seconds): ";
    cin >> time2;
    cout << "Enter time for Runner 3 (seconds): ";
    cin >> time3;

    cout << "\n--- Race Results ---\n";

    // Finding 1st, 2nd and 3rd using if-else logic

    if (time1 <= time2 && time1 <= time3) {           // Runner 1 is First
        cout << "1st Place: Runner 1 (" << time1 << "s)\n";
        
        if (time2 <= time3) {
            cout << "2nd Place: Runner 2 (" << time2 << "s)\n";
            cout << "3rd Place: Runner 3 (" << time3 << "s)\n";
        } else {
            cout << "2nd Place: Runner 3 (" << time3 << "s)\n";
            cout << "3rd Place: Runner 2 (" << time2 << "s)\n";
        }
    }
    else if (time2 <= time1 && time2 <= time3) {      // Runner 2 is First
        cout << "1st Place: Runner 2 (" << time2 << "s)\n";
        
        if (time1 <= time3) {
            cout << "2nd Place: Runner 1 (" << time1 << "s)\n";
            cout << "3rd Place: Runner 3 (" << time3 << "s)\n";
        } else {
            cout << "2nd Place: Runner 3 (" << time3 << "s)\n";
            cout << "3rd Place: Runner 1 (" << time1 << "s)\n";
        }
    }
    else {                                            // Runner 3 is First
        cout << "1st Place: Runner 3 (" << time3 << "s)\n";
        
        if (time1 <= time2) {
            cout << "2nd Place: Runner 1 (" << time1 << "s)\n";
            cout << "3rd Place: Runner 2 (" << time2 << "s)\n";
        } else {
            cout << "2nd Place: Runner 2 (" << time2 << "s)\n";
            cout << "3rd Place: Runner 1 (" << time1 << "s)\n";
        }
    }
    return 0;
}

