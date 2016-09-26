// not a particularly fast solution (n^2 with potentially O(n^3) space?? depending on amount of possible triplets (see hash map))
// only beat 11.1% of solutions

class Solution {
public:
    // this can be done in O(n^2) by first sorting nums, and then
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solutions;
        unordered_map<string, int> duplicateCheck;
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
                }
                else if (sum < 0) {
                    ptrJ++;
                }
                else {
                    stringstream ss;
                    string solutionStr;
                    ss << nums[i] << "," << nums[ptrJ] << "," << nums[ptrK];
                    ss >> solutionStr;
                    // cout << solutionStr << endl;
                    if (duplicateCheck.count(solutionStr) == 0) {
                        duplicateCheck[solutionStr] = 1;
                        solutions.push_back({nums[i], nums[ptrJ], nums[ptrK]});
                    }
                    ptrJ++;
                    // while (nums[ptrJ + 1] == nums[ptrJ]) ptrJ++;
                }
            }
            while (nums[i+1] == nums[i]) i++; // to avoid duplicates
        }
        return solutions;
    }
};