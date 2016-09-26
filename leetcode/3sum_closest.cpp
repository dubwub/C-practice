// 3 integers that sum closest to target value (basically 3sum with small change)

class Solution {
public:
    int absDiff(int x, int y) {
        return x > y ? x - y : y - x;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return -1;
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int ptrJ = i + 1;
            int ptrK = nums.size() - 1;
            int sum;
            while (ptrK > ptrJ) {
                sum = nums[i] + nums[ptrJ] + nums[ptrK];
                if (absDiff(sum, target) < absDiff(closest, target))
                    closest = sum;
                if (sum > target) {
                    ptrK--;
                    while (nums[ptrK] == nums[ptrK + 1]) ptrK--;
                }
                else if (sum < target) {
                    ptrJ++;
                    while (nums[ptrJ] == nums[ptrJ - 1]) ptrJ++;
                }
                else {
                    return target;
                }
            }
            while (nums[i+1] == nums[i]) i++; // to avoid duplicates
        }
        return closest;   
    }
};