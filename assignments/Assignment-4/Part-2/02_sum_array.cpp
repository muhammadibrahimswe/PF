// Problem 2: Sum of an Array
#include <iostream>
using namespace std;

int sumArray(int marks[], int size) {
    int sum = marks[0];
    for (int i = 1; i < size; i++) {
        sum = sum + marks[i];
    }
    return sum;
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

    cout << "SUM OF ALL VALUES ARE " << sumArray(numbers, size);
    return 0;
}
