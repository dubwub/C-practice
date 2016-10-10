/*
	Jump game part 2:
	Did this with DP with a few optimizations to make sure that it passed the best case	
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> fastestPath(nums.size(), INT_MAX);
        fastestPath[0] = 0;
        int furthestReach = 0;
        int jumpsToFurthestReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + i > furthestReach || jumpsToFurthestReach > fastestPath[i] + 1) {
                furthestReach = nums[i] + i;
                jumpsToFurthestReach = fastestPath[i] + 1;
                for (int j = i + 1; j <= i + nums[i] && j < nums.size(); j++) {
                    fastestPath[j] = fastestPath[j] > fastestPath[i] + 1 ? fastestPath[i] + 1 : fastestPath[j];
                }
            }
        }
        return fastestPath[nums.size() - 1];
    }
};