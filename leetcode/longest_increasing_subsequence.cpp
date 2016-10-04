// O n log n solution is kind of interesting, will probably implement later

/* class Solution { // O(n^2) solution, DP
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        int largest = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j] && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    if (dp[j] > largest) largest = dp[j];
                }
            }
        }
        return largest;
    }
}; */