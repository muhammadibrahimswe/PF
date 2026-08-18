// Problem 5: Get Length of a Char Array (String)
#include <iostream>
using namespace std;

int getLength(char arr[]) {
    int length = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int main() {
    char name[] = "Student";
    cout << getLength(name);
    return 0;
}
