#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
struct lex_compare {
    bool operator() (const pair<int, float>& lhs, const pair<int, float>& rhs) const{
        return lhs.first/lhs.second > rhs.first/rhs.second;
    }
};

int main() {
    int movies; float dataCap;
    cin >> movies; cin >> dataCap;
    // int limit = (int) (dataCap * 1000);
    // vector<int> dataDP((int) (dataCap * 1000) + 1);
    // vector<bool> found((int) (dataCap * 1000) + 1, false);
    multiset<pair<int,int>, lex_compare> netflix;
    //found[0] = true;
    for (int i = 0; i < movies; i++) {
        string name; float size; int enjoyment;
        cin >> name >> size >> enjoyment;
        // cout << size << endl;
        // cout << pair<int,float>(enjoyment, size).second;
        netflix.insert(pair<int,float>(enjoyment, size));
    }
    /*for (auto it = netflix.begin(); it != netflix.end() it++) {
        for (int j = 0; j < dataDP.size(); j++) {
            int newIndex = j + (int) (size * 1000);
            if (found[j] && newIndex < dataDP.size() && dataDP[newIndex] < dataDP[j] + enjoyment) {
                dataDP[newIndex] = dataDP[j] + enjoyment;
                found[newIndex] = true;
            }
        }   
    }*/
   // for (auto itit = netflix.begin(); itit != netflix.end(); itit++) {
    //    cout << itit->first << ", " << itit->second << endl;
    //}
    
    int greedy = 0;
    float used = 0;
    auto it = netflix.begin();
    while (used + it->second <= dataCap && it != netflix.end()) {
        //cout << dataCap << ", " << used << endl;
        greedy += it->first;
        used += it->second;
        //cout << dataCap << ", " << used << endl;
        it++;
    }
    //cout << greedy;
    return greedy;
}
