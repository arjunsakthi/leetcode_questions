class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the start and end points to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Bottom-up DP to calculate minimum cost
        for (int length = 2; length < m; ++length) { // Range length
            for (int i = 0; i < m - length; ++i) {
                int j = i + length; // End index of the range
                dp[i][j] = INT_MAX;

                // Try all possible cuts within the range [i, j]
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }

        // Minimum cost to cut the stick between 0 and n
        return dp[0][m - 1];
    }
};
