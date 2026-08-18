// Problem 1: Count Even and Odd numbers in an Array
#include <iostream>
using namespace std;

int countEvenNumbers(int numbers[], int size) {
    int even = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            even = even + 1;
        }
    }
    return even;
}

int countOddNumbers(int numbers[], int size) {
    int odd = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0) {
            odd = odd + 1;
        }
    }
    return odd;
}

int main() {
    int size;
    cout << "Enter the Size Of the Arrays : ";
    cin >> size;

    int numbers[size];
    cout << "Enter the Numbers : ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cout << "The Even Numbers are : " << countEvenNumbers(numbers, size) << endl;
    cout << "The Odd Numbers are : " << countOddNumbers(numbers, size);
    return 0;
}
