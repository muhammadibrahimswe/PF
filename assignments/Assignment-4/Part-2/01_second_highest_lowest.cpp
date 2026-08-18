// Problem 1: 2nd Highest and 2nd Lowest values in an Array
#include <iostream>
using namespace std;

int secondLowest(int marks[], int size) {
    int lowest = marks[0];
    int secondLowestValue = marks[0];
    for (int i = 1; i < size; i++) {
        if (marks[i] < lowest) {
            secondLowestValue = lowest;
            lowest = marks[i];
        } else if ((marks[i] < secondLowestValue || secondLowestValue == lowest) && marks[i] != lowest) {
            secondLowestValue = marks[i];
        }
    }
    return secondLowestValue;
}

int secondHighest(int marks[], int size) {
    int highest = 0;
    int secondHighestValue = marks[0];
    for (int i = 1; i < size; i++) {
        if (marks[i] > highest) {
            secondHighestValue = highest;
            highest = marks[i];
        } else if ((marks[i] > secondHighestValue || secondHighestValue == highest) && marks[i] != highest) {
            secondHighestValue = marks[i];
        }
    }
    return secondHighestValue;
}

int main() {
    int size;
    cout << "Enter the Size of The Arrays :";
    cin >> size;

    int numbers[size];
    cout << "The Numbers of Student are" << endl;
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cout << "2nd Lowest Score: " << secondLowest(numbers, size) << endl;
    cout << "2nd Highest Score: " << secondHighest(numbers, size);
    return 0;
}
