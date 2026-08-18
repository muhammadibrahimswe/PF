// Problem 3: Area Calculator (Function Overloading)
#include <iostream>
using namespace std;

double calculateArea(double side) {
    return side * side;
}

double calculateArea(double length, double width) {
    return length * width;
}

int main() {
    double sides;
    double length, width;

    cout << "Enter the side of the square: ";
    cin >> sides;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    cout << "Area of Square: " << calculateArea(sides) << endl;
    cout << "Area of Rectangle: " << calculateArea(length, width) << endl;
    return 0;
}
