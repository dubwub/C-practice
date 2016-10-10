/*
    https://leetcode.com/problems/majority-element-ii/
    Expanded majority vote to two numbers
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int one = 0; int oneCount = 0;
        int two = 0; int twoCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == one && oneCount > 0) {
                oneCount++;
            }
            else if (nums[i] == two && twoCount > 0) {
                twoCount++;
            }
            else if (oneCount == 0) {
                one = nums[i];
                oneCount = 1;
            }
            else if (twoCount == 0) {
                two = nums[i];
                twoCount = 1;
            }
            else {
                oneCount--;
                twoCount--;
            }
        }
        oneCount = 0; twoCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == one) oneCount++;
            if (nums[i] == two && two != one) twoCount++;
        }
        vector<int> returnVal;
        if (oneCount > floor(nums.size()/3)) returnVal.push_back(one);
        if (twoCount > floor(nums.size()/3)) returnVal.push_back(two);
        return returnVal;
    }
};