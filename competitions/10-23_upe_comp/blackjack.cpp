#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    vector<int> deck(13, 4);
    vector<string> cardNames = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<int> pointVals = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1};
    string card;
    int numHands;
    cin >> numHands;
    while (cin >> card) {
        for (int i = 0; i < cardNames.size(); i++) {
            if (card == cardNames[i]) {
                deck[i]--;
                break;
            }
        }
    }
    //for (int i = 0; i < deck.size(); i++) {
    //    cout << deck[i] << endl;
    //}
    int maxPoints = 0;
    for (int i = 0; i < deck.size(); i++) {
        maxPoints += deck[i] * pointVals[i];
    }
    if (maxPoints > 21) {
        cout << "Drop" << endl;
    }
    else if (maxPoints < 21) {
        for (int i = 0; i < deck[12]; i++) {
            maxPoints += 10;
            if (maxPoints >= 21) break;
        }
    }
    if (maxPoints == 21) {
        for (int i = 0; i < deck.size(); i++) {
            for (int j = 0; j < deck[i]; j++) {
                cout << "Hit" << endl;
            }
        }
    }
    return 0;
}
    