// Problem 2: Display a 2D Array
#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cout << "Enter the ROW :";
    cin >> rows;
    cout << "Enter the COLUMN :";
    cin >> columns;

    int array[rows][columns];
    cout << "Enter the Values : ";
    for (int i = 0; i < rows; i++) {
        for (int r = 0; r < columns; r++) {
            cin >> array[i][r];
        }
    }

    cout << "Enter the Values : ";
    for (int i = 0; i < rows; i++) {
        for (int r = 0; r < columns; r++) {
            cout << array[i][r] << " ";
        }
    }
    return 0;
}
