/*
	https://community.topcoder.com/stat?c=problem_statement&pm=3935&rd=6532
	successful with BFS
	150/500??? might need to figure out what the other edge cases are?
*/
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

class SmartWordToy {
private:
	void getForbidden(int distances[26][26][26][26], vector<string>& forbid) {
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
				distances[construct[0] - 'a'][construct[1] - 'a'][construct[2] - 'a'][construct[3] - 'a'] = -1;
				iterators[3]++;
				for (int j = 3; j > 0; j--) {
					if (iterators[j] >= split[j].size()) {
						iterators[j-1]++;
						iterators[j] -= split[j].size();
					}
				}
			}
		}
	}

public:
	int minPresses(string start, string finish, vector<string> forbid) {
		if (start == finish) return 0;
		int distances[26][26][26][26] = {};
		getForbidden(distances, forbid);
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
				if (manipString[i] == 'z') manipString[i] = 'a';
				else manipString[i] = manipString[i] + 1;
				if (distances[manipString[0] - 'a'][manipString[1] - 'a'][manipString[2] - 'a'][manipString[3] - 'a'] == 0) {
					distances[manipString[0] - 'a'][manipString[1] - 'a'][manipString[2] - 'a'][manipString[3] - 'a'] = poppedDist + 1;
					bfs.push(manipString);
				}
				manipString[i] = popped[i];
				if (manipString[i] == 'a') manipString[i] = 'z';
				else manipString[i] = manipString[i] - 1;
				if (distances[manipString[0] - 'a'][manipString[1] - 'a'][manipString[2] - 'a'][manipString[3] - 'a'] == 0) {
					distances[manipString[0] - 'a'][manipString[1] - 'a'][manipString[2] - 'a'][manipString[3] - 'a'] = poppedDist + 1;
					bfs.push(manipString);
				}
			}
		}
		if (popped != finish) return -1;
		return distances[finish[0] - 'a'][finish[1] - 'a'][finish[2] - 'a'][finish[3] - 'a'];
	}
};