// Problem 5: Vertical Word Printer
#include <iostream>
using namespace std;

void printVertical(char word[], int size) {
    for (int i = 0; i < size; i++) {
        cout << word[i] << endl;
    }
}

int main() {
    char word[100];
    int size = 0;
    cout << "Enter a word: ";
    cin >> word;

    while (word[size] != '\0') {
        size++;
    }

    printVertical(word, size);
    return 0;
}
