// Problem 6: Alphabetical Sorter
#include <iostream>
using namespace std;

int main() {
    char letters[5];
    for (int i = 0; i < 5; i++) {
        cin >> letters[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (letters[j] > letters[j + 1]) {
                char temp = letters[j];
                letters[j] = letters[j + 1];
                letters[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Letters: ";
    for (int i = 0; i < 5; i++) {
        cout << letters[i] << " ";
    }
    return 0;
}
