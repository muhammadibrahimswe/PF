// Problem 6: Reverse a Word
#include <iostream>
using namespace std;

void reverseWord(char word[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        char temporary = word[start];
        word[start] = word[end];
        word[end] = temporary;
        start++;
        end--;
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

    reverseWord(word, size);
    cout << word << endl;
    return 0;
}
