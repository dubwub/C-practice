/*
    https://leetcode.com/problems/majority-element/
    Done using Majority Vote algorithm
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int possibleMax = 0; int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                possibleMax = nums[i];
                count = 1;
            }
            else if (nums[i] == possibleMax) {
                count++;
            }
            else {
                count--;
            }
        }
        return possibleMax;
    }
};