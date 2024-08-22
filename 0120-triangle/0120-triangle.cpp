class Solution {
public:
int findMinPathSum(vector<vector<int>>& grid, int size) {
    vector<vector<int>> dp(size, vector<int>(size, 0));

    for (int col = 0; col < size; col++) {
        dp[size - 1][col] = grid[size - 1][col];
    }

    for (int row = size - 2; row >= 0; row--) {
        for (int col = row; col >= 0; col--) {
            int moveDown = grid[row][col] + dp[row + 1][col];
            int moveDiagonal = grid[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(moveDown, moveDiagonal);
        }
    }

    return dp[0][0];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        return findMinPathSum(triangle, triangle.size());
    }
};