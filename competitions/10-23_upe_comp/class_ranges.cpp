#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

struct compare {
    bool operator() (const pair<string, int>& lhs, const pair<string, int>& rhs) const{
        return lhs.first >= rhs.first;
    }
};

bool checkSubjs(vector<bool>& subjs) {
    for (int i = 0; i < subjs.size(); i++) {
        if (!subjs[i]) return false;
    }
    return true;
}

int main() {
    int courses;
    cin >> courses; 
    unordered_map<string, vector<string>> courseMap;
    for (int i = 0; i < courses; i++) {
        string courseName;
        cin >> courseName;
        int numSubjects;
        cin >> numSubjects;
        string subject;
        for (int i = 0; i < numSubjects; i++) {
            cin >> subject;
            if (courseMap.count(subject) == 0) {
                courseMap[subject] = vector<string>(1, courseName);
            }
            else {
                courseMap[subject].push_back(courseName);
            }
        }
    }
    int numSubjects;
    cin >> numSubjects;
    vector<string> requiredSubjs;
    vector<bool> subjs(numSubjects, false);
    unordered_map<string, vector<string>> classes;
    for (int i = 0; i < numSubjects; i++) {
        string subj;
        cin >> subj;
        requiredSubjs.push_back(subj);
        for (int j = 0; j < courseMap[subj].size(); j++) {
            if (classes.count(courseMap[subj][j]) == 0) {
                classes[courseMap[subj][j]] = vector<string>(1, subj);
            }
            else {
                classes[courseMap[subj][j]].push_back(subj);
            }
        }
    }
    int classCount = 0;
    while (!checkSubjs(subjs)) {
        int maxAdd = 0;
        string maxAddClass;
        for (auto it = classes.begin(); it != classes.end(); it++) {
            int localCount = 0;
            for (int i = 0; i < subjs.size(); i++) {
                if (subjs[i]) continue;
                for (int j = 0; j < (it->second).size(); j++) {
                    if (requiredSubjs[i] == (it->second)[j]) {
                        localCount++;
                        break;
                    }
                }
            }
            if (localCount > maxAdd) {
                maxAddClass = it->first;
                maxAdd = localCount;
            }
        }
        for (int i = 0; i < subjs.size(); i++) {
            if (subjs[i]) continue;
            for (int j = 0; j < classes[maxAddClass].size(); j++) {
                if (requiredSubjs[i] == classes[maxAddClass][j]) {
                    subjs[i] = true;
                }
            }
        }
        classCount++;
        if (maxAdd == 0) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << classCount << endl;
    return 0;
}
