// Problem 1: Sum of All Values in a 2D Array
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows";
    cin >> rows;
    cout << "Enter cols";
    cin >> cols;

    int marks[rows][cols];
    cout << "Enter the values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> marks[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += marks[i][j];
        }
    }

    cout << "Sum of all elements: " << sum << endl;
    return 0;
}
