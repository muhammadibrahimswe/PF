#include <iostream>


using namespace std;

const double PI = 3.14159265358979; // Mathematical constant pi


int main() {
cout << "=== Question 8: Geometry Calculator ===\n\n";

      int shapeChoice;
      cout << "  1. Calculate the Area of a Circle\n";
      cout << "  2. Calculate the Area of a Rectangle\n";
      cout << "  3. Calculate the Area of a Triangle\n";
      cout << "  Enter your choice (1-3): ";
      cin >> shapeChoice;

      if (shapeChoice == 1) {
        double radius;
        cout << "  Enter radius: ";
        cin >> radius;
        cout << "  Area of Circle = " << PI * radius * radius << "\n";
      } else if (shapeChoice == 2) {
        double length, width;
        cout << "  Enter length: ";
        cin >> length;
        cout << "  Enter width:  ";
        cin >> width;
        cout << "  Area of Rectangle = " << length * width << "\n";
      } else if (shapeChoice == 3) {
        double base, height;
        cout << "  Enter base:   ";
        cin >> base;
        cout << "  Enter height: ";
        cin >> height;
        cout << "  Area of Triangle = " << (base * height * 0.5) << "\n";
      } else {
        cout << "  [!] Invalid choice.\n";
    return 0;
}
}

