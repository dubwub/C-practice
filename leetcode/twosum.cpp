/*
	Two Sum: (Easy)
	Given array of ints and a target, output indices (in ascending sort) of two indices that sum to target
	Note that you can expect exactly one soln
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> values;
       for (int i = 0; i < nums.size(); i++) {
       		unordered_map<int, int>::iterator it = values.find(target - nums[i]);
       		if (it != values.end()) return std::vector<int>({it->second, i});
        	values[nums[i]] = i;
       }
       return std::vector<int>();
    }
};