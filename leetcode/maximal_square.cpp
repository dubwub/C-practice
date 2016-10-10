/*
    https://leetcode.com/submissions/detail/77601408/
    find largest square that contains all 1s in an m x n array of 0s and 1s
    DP solution (O(n^2)), where DP[i][j] = largest square that ends at i,j
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int maxSquareSide = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        int extendSquareSize = dp[i-1][j-1];
                        int x = 1;
                        bool extendable = true;
                        for (x; x <= extendSquareSize; x++) {
                            if (matrix[i-x][j] != '1' || matrix[i][j-x] != '1') {
                                extendable = false;
                                break;
                            }
                        }
                        if (extendable) {
                            dp[i][j] = extendSquareSize + 1;
                        }
                        else {
                            dp[i][j] = x;
                        }
                    }
                    if (dp[i][j] > maxSquareSide) maxSquareSide = dp[i][j];
                }
            }
        }
        // for (int i = 0; i < matrix.size(); i++) {
        //     for (int j = 0; j < matrix[i].size(); j++) {
        //         cout << dp[i][j];
        //     }
        //     cout << endl;
        // }
        return maxSquareSide * maxSquareSide;
    }
};  