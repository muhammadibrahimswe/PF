// Problem 6: Copy a Word into Another Char Array
#include <iostream>
using namespace std;

void copyWord(char src[], char dest[], int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

int main() {
    char original[] = "Code";
    char backup[10];
    copyWord(original, backup, 4);
    cout << backup;
    return 0;
}
