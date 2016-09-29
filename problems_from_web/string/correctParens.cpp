#include <iostream>
#include <string>
#include <vector>
using namespace std;

// take a string containing parenthesis and correct parens

class Solution {
public:
	string correctParens(string& input) {
		string firstPass = ""; // first go left to right
		int parenScore = 0;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(')
				parenScore++;
			else if (input[i] == ')') {
				if (parenScore == 0) continue;
				parenScore--;
			}
			firstPass += input[i];
		}
		string secondPass = "";
		parenScore = 0;
		for (int i = firstPass.size()-1; i >= 0; i--) {
			if (firstPass[i] == ')')
				parenScore++;
			else if (firstPass[i] == '(') {
				if (parenScore == 0) continue;
				parenScore--;
			}
			secondPass = firstPass[i] + secondPass;
		}
		return secondPass;
	}	
};

int main() {
	Solution s;
	vector<string> tests = {
		"()(",
		"(()",
		"(())",
		"()()",
		"",
		"(",
		")",
		"(((()()))",
		"(((()))))"
	};
	for (int i = 0; i < tests.size(); i++) {
		cout << tests[i] << " --> " << s.correctParens(tests[i]) << endl;
	}
}