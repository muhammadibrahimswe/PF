// Problem 5: Cricket Team Initial Finder
#include <iostream>
using namespace std;

bool searchPlayer(char players[], int size, char matchCharacter) {
    for (int i = 0; i < size; i++) {
        if (matchCharacter == players[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;
    char matchCharacter;
    cout << "Enter the Length that how much player you want to add : ";
    cin >> size;

    char players[size];
    cout << "Enter the First Word of The Player Name ";
    for (int i = 0; i < size; i++) {
        cin >> players[i];
    }

    cout << "Enter the Player First Character that You want to Match : ";
    cin >> matchCharacter;

    if (searchPlayer(players, size, matchCharacter)) {
        cout << "Player is in the team";
    } else {
        cout << "Player not found";
    }
    return 0;
}
