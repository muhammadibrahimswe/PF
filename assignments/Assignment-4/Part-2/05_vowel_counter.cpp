// Problem 5: Vowel Counter
#include <iostream>
using namespace std;

int totalVowels(char word[]) {
    int total = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
            total = total + 1;
        }
    }
    return total;
}

int main() {
    char word[100];
    cin >> word;
    cout << "Total Vowels: " << totalVowels(word);
    return 0;
}
