// given a string and list of words, see if you can build the string out of the list of words
// i.e. "leetcake" [leet, cake] should return true
// originally did recursive solution, but DP is way better (knapsack kinda), beat 90% of submissions

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int maxStringSize = 0;
        for (const auto& elem : wordDict) {
            if (elem.size() > maxStringSize) maxStringSize = elem.size();
        }
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - maxStringSize; j <= i; j++) {
                if (j < 0 || dp[j] == 0) continue;
                if (wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i];
        // }
        // cout << endl;
        return dp[s.size()] == 1 ? true : false;
    }
};

// class Solution { // recursive
// public:
//     bool wordBreak(string s, unordered_set<string>& wordDict) {
//         if (s.size() == 0) return true;
//         for (int i = 1; i <= s.size(); i++) {
//             if (wordDict.find(s.substr(0, i)) != wordDict.end() && wordBreak(s.substr(i), wordDict))
//                 return true;
//         }
//         return false;
//     }
// };