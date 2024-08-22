class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int col = 0; col < cols; col++) {
            dp[0][col] = matrix[0][col];
        }

        for (int row = 1; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int up = matrix[row][col] + dp[row - 1][col];
                
                int leftDiagonal = matrix[row][col];
                if (col - 1 >= 0) {
                    leftDiagonal += dp[row - 1][col - 1];
                } else {
                    leftDiagonal += 1e9;
                }

                int rightDiagonal = matrix[row][col];
                if (col + 1 < cols) {
                    rightDiagonal += dp[row - 1][col + 1];
                } else {
                    rightDiagonal += 1e9;
                }

                dp[row][col] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        int maxSum = INT_MAX;
        for (int col = 0; col < cols; col++) {
            maxSum = min(maxSum, dp[rows - 1][col]);
        }

        return maxSum;
    }
};
