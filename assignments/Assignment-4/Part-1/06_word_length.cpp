// Problem 6: Word Length Calculator
#include <iostream>
using namespace std;

int main() {
    char word[100];
    cout << "Enter the Single Word";
    cin >> word;

    int length = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        length = length + 1;
    }
    cout << length;
    return 0;
}
