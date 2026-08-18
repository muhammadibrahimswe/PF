// Problem 1: Average of values in an Array
#include <iostream>
using namespace std;

double calculateAverage(int marks[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + marks[i];
    }
    return (double)sum / size;
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

    cout << "The Average is " << calculateAverage(numbers, size);
    return 0;
}
