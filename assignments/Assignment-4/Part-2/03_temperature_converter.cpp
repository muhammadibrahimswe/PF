// Problem 3: Temperature Converter (Celsius to Fahrenheit)
#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    double celsius;
    cout << "Add Temperature in Celcius";
    cin >> celsius;
    cout << celsiusToFahrenheit(celsius);
    return 0;
}
