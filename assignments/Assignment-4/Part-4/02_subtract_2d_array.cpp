// Problem 2: Subtract All Values from the First Element
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows";
    cin >> rows;
    cout << "Enter cols";
    cin >> cols;

    int profitTable[rows][cols];
    cout << "Enter the values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> profitTable[i][j];
        }
    }

    int result = profitTable[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            result -= profitTable[i][j];
        }
    }

    cout << "result: " << result << endl;
    return 0;
}
