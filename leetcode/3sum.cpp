// huge performance increase by removing the hashmap in favor of just getting rid of duplicate checks

class Solution {
public:
    // this can be done in O(n^2) by assuming each subsequent value is the first number, and then solving two sum essentially
    // first you sort, and every time you increment/decrement make sure that pointers are sane (j < k) and that you aren't checking
    // the exact same thing
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solutions;
        if (nums.size() < 3) return solutions; // this shouldn't be crashing though??
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int ptrJ = i + 1;
            int ptrK = nums.size() - 1;
            int sum;
            while (ptrK > ptrJ) {
                sum = nums[i] + nums[ptrJ] + nums[ptrK];
                if (sum > 0) {
                    ptrK--;
                    while (nums[ptrK] == nums[ptrK + 1]) ptrK--;
                }
                else if (sum < 0) {
                    ptrJ++;
                    while (nums[ptrJ] == nums[ptrJ - 1]) ptrJ++;
                }
                else {
                    solutions.push_back({nums[i], nums[ptrJ], nums[ptrK]});
                    ptrJ++;
                    while (nums[ptrJ] == nums[ptrJ - 1]) ptrJ++;
                }
            }
            while (nums[i+1] == nums[i]) i++; // to avoid duplicates
        }
        return solutions;
    }
};