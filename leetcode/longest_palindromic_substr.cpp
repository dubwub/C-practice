// My solution is definitely O(n^2) with very little overlap, but I think the fact that it's recursive
// hurt it a lot. I read their post-mortem and my solution was basically their expand around center, so
// just as practice i'm going to implement that.

// this worked blazingly fast

class Solution {
public:
	string expandAroundCenter(string s, int i, int j) {
		int best_i = i;
		int best_j = j;
		while (i >= 0 && j < s.size() && s[i] == s[j]) {
			best_i = i; best_j = j;
			i--; j++;
		}
		return s.substr(best_i, best_j - best_i + 1);
	}

	string longestPalindrome(string s) {
		if (s.size() == 0) return "";
		if (s.size() == 1) return s;
		string longest = "";
		for (int i = 0; i < s.size(); i++) {
			string output = expandAroundCenter(s, i, i);
			if (output.size() > longest.size()) longest = output;
			if (i + 1 < s.size() && s[i] == s[i+1]) {
				output = expandAroundCenter(s, i, i+1);
			}
			if (output.size() > longest.size()) longest = output;
		}
		return longest;
	}
};