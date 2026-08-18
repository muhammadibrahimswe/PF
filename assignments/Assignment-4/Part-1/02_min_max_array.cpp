// Problem 2: Largest and Smallest values in an Array
#include <iostream>
using namespace std;

int calculateLowest(int marks[], int size) {
    int lowest = marks[0];
    for (int i = 0; i < size; i++) {
        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }
    return lowest;
}

int calculateHighest(int marks[], int size) {
    int highest = marks[0];
    for (int i = 0; i < size; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }
    return highest;
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

    cout << "The Lowest Number of the Array is : " << calculateLowest(numbers, size) << endl;
    cout << "The Highest Number of the Array is : " << calculateHighest(numbers, size);
    return 0;
}
