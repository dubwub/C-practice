// longest palindromic substring
// should be O(n^2), but apparently it's too slow
// did this using dynamic programming

class Solution {
public:
    // note: only call this where [i][j] is confirmed palindrome
    // this will branch out further and fill out all other palindromes around it
    vector<int> fillSubproblems(/*vector<vector<int>> &subproblems, */string& s, int i, int j) {
        cout << i << ", " << j << endl;
        vector<int> largestPalindrome = {i, j};
        if (i == j) { // just in case the middle of the palindrome is two characters
            if (i+1 < s.size() && s[i+1] == s[i]) {
                // subproblems[i][i+1] = 1;
                vector<int> result = fillSubproblems(/*subproblems, */s, i, i+1);
                if (result[1] - result[0] > largestPalindrome[1] - largestPalindrome[0]) {
                    largestPalindrome[0] = result[0];
                    largestPalindrome[1] = result[1];
                }
            }
        }
        if (i == 0 || j == s.size() - 1) return largestPalindrome;
        if (s[i-1] == s[j+1]) {
            // subproblems[i-1][j+1] = 1;
            vector<int> result = fillSubproblems(/*subproblems, */s, i-1, j+1);
            if (result[1] - result[0] > largestPalindrome[1] - largestPalindrome[0]) {
                largestPalindrome[0] = result[0];
                largestPalindrome[1] = result[1];
            }
        }
        return largestPalindrome;
    }

    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        int largest_i = 0;
        int largest_j = 0;
        // sp[i][j] = 1 if i --> j is a subproblem
        // vector<vector<int>> subproblems(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            // subproblems[i][i] = 1;
            vector<int> result = fillSubproblems(/*subproblems, */s, i, i);
            if (result[1] - result[0] > largest_j - largest_i) {
                largest_i = result[0];
                largest_j = result[1];
            }
        }
        cout << largest_i << ", " << largest_j << endl;
        return s.substr(largest_i, largest_j - largest_i + 1);
    }
};