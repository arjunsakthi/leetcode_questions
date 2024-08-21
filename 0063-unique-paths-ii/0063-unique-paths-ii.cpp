class Solution {
public:
   int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (i >= 0 && j >= 0 && maze[i][j] == 1) {
                dp[i][j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1; // If we are at the starting point, there is one path to it
                continue;
            }

            int up = 0;
            int left = 0;

            // Check if we can move up and left (if not at the edge of the maze)
            if (i > 0)
                up = dp[i - 1][j]; // Number of paths from above
            if (j > 0)
                left = dp[i][j - 1]; // Number of paths from the left

            // Total number of paths to reach (i, j) is the sum of paths from above and left
            dp[i][j] = up + left;
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
        
    return mazeObstaclesUtil(n, m, obstacleGrid, dp); 
    }
};