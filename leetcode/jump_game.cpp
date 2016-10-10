/*
	https://leetcode.com/problems/jump-game/
	given an array of ints [2, 3, 0, 1, 2]
	you start at index 0 and can jump from that index to anywhere from 0 to nums[index] from your position
	return whether you can hit the end
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthestReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (furthestReach >= nums.size() - 1) return true; 
            if (i > furthestReach) return false;
            furthestReach = nums[i] + i > furthestReach ? nums[i] + i : furthestReach;
        }
        return true;
    }
};