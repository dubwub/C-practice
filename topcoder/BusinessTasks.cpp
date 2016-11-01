/*
	https://community.topcoder.com/stat?c=problem_statement&pm=1585&rd=6535
	Successful, 499.91/500

	postmortem: turns out trying to solve this in-place without modifying the array (trying to get around the O(N) erase from vector)
	makes it pretty impossible to get under the time limit for large values of n

	also turns out modifying array as you go through is pretty stupid
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class BusinessTasks {
public:
	string getTask(vector<string> tasks, int n) {
		int it = 0;
		while (tasks.size() > 1) {
			it = (it + n - 1) % tasks.size();
			tasks.erase(tasks.begin() + it);
			if (it >= tasks.size()) it -= tasks.size();
		}
		return tasks[0];
	}
	// string getTask(vector<string>& tasks, int n) {
	// 	n %= tasks.size();
	// 	int it = 0;
	// 	for (int i = 0; i < tasks.size() - 1; i++) {
	// 		for (int j = 0; j < n; j++) {
	// 			while (tasks[it] == "") {
	// 				it++;
	// 				if (it == tasks.size()) it = 0;
	// 			}
	// 			it++;
	// 			if (it == tasks.size()) it = 0;
	// 		}
	// 		it--;
	// 		if (it < 0) it += tasks.size();
	// 		tasks[it] = "";
	// 	}
	// 	int i = 0;
	// 	while (tasks[i] == "" && i < tasks.size()) i++;
	// 	return tasks[i];
	// }
};