/*
    https://leetcode.com/problems/wiggle-subsequence/
    find longest subsequence where numbers alternate strictly larger smaller larger smaller (than previous)
    or smaller larger etc.

    had to read the editorial to get the O(n) solution unfortunately
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int wiggleLength = 1;
        int sign = 0; // +1 means looking for a bigger, -1 searches for smaller
        for (int i = 1; i < nums.size(); i++) {
            if (sign == 0) { // initialize sign
                if (nums[i] != nums[i - 1]) {
                    sign = nums[i] > nums[i-1] ? -1 : 1;
                    wiggleLength++;
                }
            }
            else if (sign == -1 && nums[i] < nums[i-1]) {
                sign = 1;
                wiggleLength++;
            }
            else if (sign == 1 && nums[i] > nums[i-1]) {
                sign = -1;
                wiggleLength++;
            }
        }
        return wiggleLength;
    }
};

// DP solution O(n^2)
/*class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int maxWiggleLen = 0;
        // dp[i][0] = max length of wiggle sequence that starts ascending here
        // dp[1][1] = same thing but starts with descending
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j] && dp[i][1] < dp[j][0] + 1) // append to existing ascending chain
                    dp[i][1] = dp[j][0] + 1;
                if (nums[j] > nums[i] && dp[i][0] < dp[j][1] + 1) // append to existing desc. chain
                    dp[i][0] = dp[j][1] + 1;
            }
            if (dp[i][0] > maxWiggleLen) maxWiggleLen = dp[i][0];
            if (dp[i][1] > maxWiggleLen) maxWiggleLen = dp[i][1];
        }
        return maxWiggleLen;
    }
};*/