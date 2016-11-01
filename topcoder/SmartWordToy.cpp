/*
	https://community.topcoder.com/stat?c=problem_statement&pm=3935&rd=6532
*/
#include <vector>
#include <array>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;

class SmartWordToy {
private:
	unordered_set<string> getForbidden(vector<string>& forbid) {
		unordered_set<string> forbiddenSet;
		for (string s : forbid) {
			stringstream ss;
			ss << s;
			string tmp;
			vector<string> split;
			for (int i = 0; i < 4; i++) {
				ss >> tmp;
				split.push_back(tmp);
			}
			vector<int> iterators = {0, 0, 0, 0};
			while (iterators[0] < split[0].size()) {
				string construct = "";
				for (int i = 0; i < 4; i++) {
					construct += split[i][iterators[i]];
				}
				forbiddenSet.insert(construct);
				iterators[3]++;
				for (int j = 3; j > 0; j--) {
					if (iterators[j] >= split[j].size()) {
						iterators[j-1]++;
						iterators[j] -= split[j].size();
					}
				}
			}
		}
		return forbiddenSet;
	}

public:
	int minPresses(string start, string finish, vector<string> forbid) {
		if (start == finish) return 0;
		unordered_set<string> forbidden = getForbidden(forbid);
		int distances[26][26][26][26];
		distances[start[0] - 'a'][start[1] - 'a'][start[2] - 'a'][start[3] - 'a'] = 0;
		queue<string> bfs;
		bfs.push(start);
		string popped = bfs.front();
		while (!bfs.empty() && popped != finish) {
			popped = bfs.front();
			bfs.pop();
			int poppedDist = distances[popped[0] - 'a'][popped[1] - 'a'][popped[2] - 'a'][popped[3] - 'a'];
			string manipString = popped;
			for (int i = 0; i < 4; i++) {
				manipString = popped;
				for (char j = 'a'; j <= 'z'; j++) {
					manipString[i] = j;
					if (forbidden.find(manipString) == forbidden.end() 
						&& distances[manipString[0] - 'a'][manipString[1] - 'a'][manipString[2] - 'a'][manipString[3] - 'a'] == 0) {
						distances[manipString[0] - 'a'][manipString[1] - 'a'][manipString[2] - 'a'][manipString[3] - 'a'] = poppedDist + 1;
						bfs.push(manipString);
					}
				}
			}
		}
		return distances[finish[0] - 'a'][finish[1] - 'a'][finish[2] - 'a'][finish[3] - 'a'];
	}
};