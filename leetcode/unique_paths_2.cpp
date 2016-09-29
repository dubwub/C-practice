// given m x n array of 0s and 1s
// [ 0 0 0 ]
// [ 0 1 0 ]
// [ 0 0 0 ]
// return number of paths from top left to bottom right assuming you can't go into 1s
// for instance above should return 2

class Solution {
public:
    // DP: grid[x][y] = number of paths from x,y to the finish
    // end is initialized to 1
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) return 0;
        obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] = 1;
        for (int x = obstacleGrid.size() - 1; x >= 0; x--) {
            for (int y = obstacleGrid[0].size() - 1; y >= 0; y--) {
                if (x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size() - 1)
                    continue;
                else if (obstacleGrid[x][y] == 1) {
                    obstacleGrid[x][y] = 0;
                    continue;
                }
                obstacleGrid[x][y] = 0;
                if (x + 1 < obstacleGrid.size())
                    obstacleGrid[x][y] += obstacleGrid[x+1][y];
                if (y + 1 < obstacleGrid[x].size())
                    obstacleGrid[x][y] += obstacleGrid[x][y+1];
            }
        }
        // for (int i = 0; i < obstacleGrid.size(); i++) {
        //     for (int j = 0; j < obstacleGrid[0].size(); j++) {
        //         cout << obstacleGrid[i][j] << endl;
        //     }
        // }
        return obstacleGrid[0][0];
    }
};